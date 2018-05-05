#include "Renderer.h"
#include "DebugUtil.h"

void Renderer::renderMesh(Framebuffer & target, const Texture& texture, Mesh mesh, const Mat4& mvp, const Mat4& mv, const Vec3 & color) {
	std::vector<Vertex>& vertices = mesh.getVertices();
	std::vector<int> indices = mesh.getIndices();
	int faces = indices.size() / 3;
	for (int i = 0; i < faces; i++) {
		renderTriangle(
			target,
			texture,
			vertices[indices[i * 3 + 0]],
			vertices[indices[i * 3 + 1]],
			vertices[indices[i * 3 + 2]],
			mvp,
			mv
		);
	}
}

void Renderer::renderTriangle(Framebuffer& target, const Texture& texture, Vertex v1, Vertex v2, Vertex v3, const Mat4& mvp, const Mat4& mv) {

	v1.transformToScreen(mvp, mv, target.getWidth(), target.getHeight());
	v2.transformToScreen(mvp, mv, target.getWidth(), target.getHeight());
	v3.transformToScreen(mvp, mv, target.getWidth(), target.getHeight());

	if(v1.handedness(v2, v3))return;

	Vertex* top = &v1;
	Vertex* mid = &v2;
	Vertex* bot = &v3;
	Vertex* temp;

	if (top->compareY(*mid)) {
		temp = mid;
		mid = top;
		top = temp;
	}
	if (top->compareY(*bot)) {
		temp = bot;
		bot = top;
		top = temp;
	}
	if (mid->compareY(*bot)) {
		temp = bot;
		bot = mid;
		mid = temp;
	}

	Gradients grad(*top, *mid, *bot);

	Edge topToBot(grad, *top, *bot, 0);
	Edge topToMid(grad, *top, *mid, 0);
	Edge midToBot(grad, *mid, *bot, 1);

	bool handedness = top->handedness(*mid, *bot);

	Edge* left;
	Edge* right;

	if (handedness) {
		left = &topToBot;
		right = &topToMid;
	}
	else {
		left = &topToMid;
		right = &topToBot;
	}
	scanTriangleHalf(target, texture, left, right, topToMid.getYStart(), topToMid.getYEnd());

	if (handedness) {
		right = &midToBot;
	}
	else {
		left = &midToBot;
	}
	scanTriangleHalf(target, texture, left, right, midToBot.getYStart(), midToBot.getYEnd());
}

void Renderer::scanTriangleHalf(Framebuffer& target, const Texture& texture,  Edge* left, Edge* right, int yStart, int yEnd) {
	for (int y = yStart; y < yEnd; y++) {
		int xStart = (int)ceil(left->getXPos());
		int xEnd = (int)ceil(right->getXPos());
		float xPre = (float)xStart - left->getXPos();
		
		float oneOverXDist = 1.0f / (right->getXPos() - left->getXPos());
		Vec2 texCoordsXStep = (right->getTexCoords() - left->getTexCoords()) * oneOverXDist;
		Vec3 normalXStep = (right->getNormal() - left->getNormal()) * oneOverXDist;
		float oneOverZXStep = (right->getOneOverZ() - left->getOneOverZ()) * oneOverXDist;
		float depthXStep = (right->getDepth() - left->getDepth()) * oneOverXDist;

		Vec2 texCoordsDivZ = left->getTexCoords() + texCoordsXStep * xPre;
		Vec3 normalDivZ = left->getNormal() + normalXStep * xPre;
		float oneOverZ = left->getOneOverZ() + oneOverZXStep * xPre;
		float depth = left->getDepth() + depthXStep * xPre;

		for (int x = xStart; x < xEnd; x++) {
			float z = 1.0f / oneOverZ;
			Vec2 texCoord = texCoordsDivZ * z;
			Vec3 normal = normalDivZ * z;
			normal.normalize();
			float lightFactor = dot(normalize(Vec3( 0.2f, -0.5f, -1.0f )), normal);
			if (lightFactor < 0)lightFactor = 0;
			Vec3 color = texture.sample(texCoord) * lightFactor;
			if (depth < target.getDepth(x, y)) {
				target.setPixel(x, y, ((int)(color.x * 255.0f)) | ((int)(color.y * 255.0f) << 8) | ((int)(color.z * 255.0f) << 16), depth);
			}
			texCoordsDivZ += texCoordsXStep;
			normalDivZ += normalXStep;
			oneOverZ += oneOverZXStep;
			depth += depthXStep;
		}
		left->step();
		right->step();
	}
}