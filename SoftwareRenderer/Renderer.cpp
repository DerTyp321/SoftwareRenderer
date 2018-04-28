#include "Renderer.h"

#define MIN(x, y) ((x) < (y) ? (x):(y))
#define MAX(x, y) ((x) > (y) ? (x):(y))

void Renderer::renderRect(Framebuffer& target, int startX, int startY, int width, int height, const Vec3& color) {
	for (int y = MAX(0, startY); y < MIN(target.getHeight(), startY + height); y++) {
		for (int x = MAX(0, startX); x < MIN(target.getWidth(), startX + width); x++) {
			target.setRGB(x, y, (int)(color.x * 255), (int)(color.y * 255), (int)(color.z * 255));
		}
	}
}

void Renderer::renderTriangle(Framebuffer& target, const Vec2& v1,const Vec2& v2, const Vec2& v3, const Vec3& color) {
	Vec2 temp;
	Vec2 top = v1;
	Vec2 mid = v2;
	Vec2 bot = v3;
	if (top.y > mid.y) {
		temp = mid;
		mid = top;
		top = temp;
	}
	if (top.y > bot.y) {
		temp = bot;
		bot = top;
		top = temp;
	}
	if (mid.y > bot.y) {
		temp = bot;
		bot = mid;
		mid = temp;
	}

	int yStart = (int)top.y;
	int yMid = (int)mid.y;
	int yEnd = (int)bot.y;

	float xStep = (bot.x - top.x) / (bot.y - top.y);
	float x = top.x;

	for (int y = yStart; y < yEnd; y++) {
		target.setScanbufferStartX(y, (int)x);
		x += xStep;
	}

	xStep = (mid.x - top.x) / (mid.y - top.y);
	x = top.x;

	for (int y = yStart; y < yMid; y++) {
		target.setScanbufferEndX(y, (int)x);
		x += xStep;
	}

	xStep = (bot.x - mid.x) / (bot.y - mid.y);
	x = mid.x;

	for (int y = yMid; y < yEnd; y++) {
		target.setScanbufferEndX(y, (int)x);
		x += xStep;
	}


	for (int y = yStart; y < yEnd; y++) {
		int xStart = target.getScanbufferStartX(y);
		int xEnd = target.getScanbufferEndX(y);
		for (int x = xStart; x < xEnd; x++) {
			target.setRGB(x, y, (int)(color.x * 255), (int)(color.y * 255), (int)(color.z * 255));
		}
	}
}