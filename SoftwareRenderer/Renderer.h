#pragma once
#include "Framebuffer.h"
#include "MathUtil.h"
#include "Mesh.h"
#include "Edge.h"

class Renderer {
public:
	void renderRect(Framebuffer& target, int x, int y, int width, int height, const Vec3& color);
	void renderMesh(Framebuffer & target, Mesh mesh, Mat4 mvp, const Vec3 & color);
private:
	void renderTriangle(Framebuffer& target, Vertex v1, Vertex v2, Vertex v3, const Mat4& mvp);
	void scanTriangleHalf(Framebuffer& target, Edge* left, Edge* right, int yStart, int yEnd);
};