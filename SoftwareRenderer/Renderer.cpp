#include "Renderer.h"

#define MIN(x, y) ((x) < (y) ? (x):(y))
#define MAX(x, y) ((x) > (y) ? (x):(y))

void Renderer::renderRect(Framebuffer* target, int x, int y, int width, int height, Vec3 color) {
	unsigned char* colorBuffer = target->getColorBuffer();
	for (int cy = MAX(0, y); cy < MIN(target->getHeight(), y + height); cy++) {
		for (int cx = MAX(0, x); cx < MIN(target->getWidth(), x + width); cx++) {
			colorBuffer[(cy * target->getWidth() + cx) * 3 + 0] = (int)(color.x * 255);
			colorBuffer[(cy * target->getWidth() + cx) * 3 + 1] = (int)(color.y * 255);
			colorBuffer[(cy * target->getWidth() + cx) * 3 + 2] = (int)(color.z * 255);
		}
	}
}

void Renderer::renderTriangle(Framebuffer* target, Vec2 v1, Vec2 v2, Vec2 v3, Vec3 color) {
	Vec2 top = v1;
	Vec2 mid = v2;
	Vec2 bot = v3;
	Vec2 temp;
	if (v1.y > v2.y) {
		temp = v2;
		v2 = v1;
		v1 = temp;
	}
	if (v1.y > v3.y) {
		temp = v3;
		v3 = v1;
		v1 = temp;
	}
	if (v2.y > v3.y) {
		temp = v3;
		v3 = v2;
		v2 = temp;
	}

	unsigned char* colorBuffer = target->getColorBuffer();
	
	float xStep = (bot.x - top.x) / (bot.y - top.y);
	float x = top.x;

	for (int y = (int)top.y; y < (int)bot.y; y++) {
		x += xStep;
		colorBuffer[(y * target->getWidth() + (int)x) * 3 + 0] = (int)(color.x * 255);
		colorBuffer[(y * target->getWidth() + (int)x) * 3 + 1] = (int)(color.y * 255);
		colorBuffer[(y * target->getWidth() + (int)x) * 3 + 2] = (int)(color.z * 255);
	}

	xStep = (mid.x - top.x) / (mid.y - top.y);
	x = top.x;

	for (int y = (int)top.y; y < (int)mid.y; y++) {
		x += xStep;
		colorBuffer[(y * target->getWidth() + (int)x) * 3 + 0] = (int)(color.x * 255);
		colorBuffer[(y * target->getWidth() + (int)x) * 3 + 1] = (int)(color.y * 255);
		colorBuffer[(y * target->getWidth() + (int)x) * 3 + 2] = (int)(color.z * 255);
	}

	xStep = (bot.x - mid.x) / (bot.y - mid.y);
	x = mid.x;

	for (int y = (int)mid.y; y < (int)bot.y; y++) {
		x += xStep;
		colorBuffer[(y * target->getWidth() + (int)x) * 3 + 0] = (int)(color.x * 255);
		colorBuffer[(y * target->getWidth() + (int)x) * 3 + 1] = (int)(color.y * 255);
		colorBuffer[(y * target->getWidth() + (int)x) * 3 + 2] = (int)(color.z * 255);
	}
}