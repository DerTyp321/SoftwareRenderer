#include "Renderer.h"
#include "DebugUtil.h"

#define MIN(x, y) ((x) < (y) ? (x):(y))
#define MAX(x, y) ((x) > (y) ? (x):(y))

void Renderer::renderRect(Framebuffer& target, int startX, int startY, int width, int height, const Vec3& color) {
	for (int y = MAX(0, startY); y < MIN(target.getHeight(), startY + height); y++) {
		for (int x = MAX(0, startX); x < MIN(target.getWidth(), startX + width); x++) {
			target.setRGB(x, y, (int)(color.x * 255), (int)(color.y * 255), (int)(color.z * 255));
		}
	}
}

void Renderer::renderMesh(Framebuffer & target, Mesh mesh, Mat4 mvp, const Vec3 & color) {
	std::vector<Vertex>& vertices = mesh.getVertices();
	std::vector<int> indices = mesh.getIndices();
	int faces = indices.size() / 3;
	for (int i = 0; i < faces; i++) {
		renderTriangle(
			target,
			vertices[indices[i * 3 + 0]],
			vertices[indices[i * 3 + 1]],
			vertices[indices[i * 3 + 2]],
			mvp
		);
	}
}

void Renderer::renderTriangle(Framebuffer& target, Vertex v1, Vertex v2, Vertex v3, const Mat4& mvp) {

	v1.transformToScreen(mvp, target.getWidth(), target.getHeight());
	v2.transformToScreen(mvp, target.getWidth(), target.getHeight());
	v3.transformToScreen(mvp, target.getWidth(), target.getHeight());

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
	scanTriangleHalf(target, left, right, topToMid.getYStart(), topToMid.getYEnd());

	if (handedness) {
		right = &midToBot;
	}
	else {
		left = &midToBot;
	}
	scanTriangleHalf(target, left, right, midToBot.getYStart(), midToBot.getYEnd());
}

void Renderer::scanTriangleHalf(Framebuffer& target, Edge* left, Edge* right, int yStart, int yEnd) {
	for (int y = yStart; y < yEnd; y++) {
		int xStart = (int)ceil(left->getXPos());
		int xEnd = (int)ceil(right->getXPos());
		Vec3 colorStart = left->getColor();
		Vec3 colorEnd = right->getColor();
		float lerpAmt = 0.0f;
		float lerpStep = 1.0f / (float)(xEnd-xStart);
		for (int x = xStart; x < xEnd; x++) {
			Vec3 color = colorStart.lerp(colorEnd, lerpAmt);
			target.setRGB(x, y, (int)(color.x * 255.0f + 0.5f), (int)(color.y * 255.0f + 0.5f), (int)(color.z * 255.0f + 0.5f));
			lerpAmt += lerpStep;
		}
		left->step();
		right->step();
	}
}