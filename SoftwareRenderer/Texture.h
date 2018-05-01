#pragma once
#include "MathUtil.h"

class Texture {
public:
	Texture(int width, int height);
	~Texture();
	void setPixel(int x, int y, int abgr);
	Vec3 sample(Vec2 coords) const;
private:
	int m_width;
	int m_height;
	int* m_colorBuffer;
};