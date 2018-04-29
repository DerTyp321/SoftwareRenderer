#pragma once
#include "Framebuffer.h"
#include "Mat4.h"
#include "Vec4.h"
#include "Vec3.h"
#include "Vec2.h"

class Renderer {
public:
	void renderRect(Framebuffer& target, int x, int y, int width, int height, const Vec3& color);
	void renderTriangle3D(Framebuffer& target, const Vec4& v1, const Vec4& v2, const Vec4& v3, Mat4 model, Mat4 view, Mat4 projection, const Vec3& color);
	void renderTriangle(Framebuffer& target, const Vec2& v1, const Vec2& v2, const Vec2& v3, const Vec3& color);
private:
};