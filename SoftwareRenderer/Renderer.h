#pragma once
#include "Framebuffer.h"
#include "MathUtil.h"
#include "Mesh.h"
#include "Edge.h"
#include "Texture.h"

class Renderer {
public:
	void renderMesh(Framebuffer & target, const Texture& texture, Mesh mesh, Mat4 mvp, const Vec3 & color);
private:
	void renderTriangle(Framebuffer& target, const Texture& texture, Vertex v1, Vertex v2, Vertex v3, const Mat4& mvp);
	void scanTriangleHalf(Framebuffer& target, const Texture& texture, Edge* left, Edge* right, int yStart, int yEnd);
};