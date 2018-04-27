#pragma once
#include "Framebuffer.h"
#include "Vec3.h"
#include "Vec2.h"

class Renderer {
public:
	void renderRect(Framebuffer* target, int x, int y, int width, int height, Vec3 color);
	void renderTriangle(Framebuffer* target, Vec2 v1, Vec2 v2, Vec2 v3, Vec3 color);
private:
};