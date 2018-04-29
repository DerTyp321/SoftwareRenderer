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

void Renderer::renderTriangle3D(Framebuffer& target, const Vec4& v1,const Vec4& v2, const Vec4& v3, Mat4 model, Mat4 view, Mat4 projection, const Vec3& color) {
	Mat4 mvp = projection * view * model;

	Vec4 v1Screen = v1 * mvp;
	Vec4 v2Screen = v2 * mvp;
	Vec4 v3Screen = v3 * mvp;
	v1Screen.zDiv();
	v2Screen.zDiv();
	v3Screen.zDiv();
	
	renderTriangle(target, Vec2{v1Screen.x, v1Screen.y}, Vec2{ v2Screen.x, v2Screen.y }, Vec2{ v3Screen.x, v3Screen.y }, color);
}

void Renderer::renderTriangle(Framebuffer& target, const Vec2& v1, const Vec2& v2, const Vec2& v3, const Vec3& color) {
	Vec2 top = v1;
	Vec2 mid = v2;
	Vec2 bot = v3;
	Vec2 temp;
	Vec2 offset{ 1.0f, 1.0f};
	Vec2 scale{ target.getWidth() / 2.0f, target.getHeight() / 2.0f };
	top.add(offset).mul(scale);
	mid.add(offset).mul(scale);
	bot.add(offset).mul(scale);

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

	Vec2 top2{ top.x, top.y };
	Vec2 mid2{ mid.x, mid.y };
	Vec2 bot2{ bot.x, bot.y };
	int handedness = cross(bot2 - top2, mid2 - top2) >= 0.0f ? 1 : 0;

	float xStep = (bot.x - top.x) / (bot.y - top.y);
	float x = top.x;

	for (int y = yStart; y < yEnd; y++) {
		target.setScanbufferX(y, (int)x, handedness);
		x += xStep;
	}

	xStep = (mid.x - top.x) / (mid.y - top.y);
	x = top.x;

	for (int y = yStart; y < yMid; y++) {
		target.setScanbufferX(y, (int)x, 1 - handedness);
		x += xStep;
	}

	xStep = (bot.x - mid.x) / (bot.y - mid.y);
	x = mid.x;

	for (int y = yMid; y < yEnd; y++) {
		target.setScanbufferX(y, (int)x, 1 - handedness);
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