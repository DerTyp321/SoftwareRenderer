#pragma once
#include "MathUtil.h"

class Texture {
public:
	Texture(int width, int height);
	~Texture();
	void setPixel(int x, int y, unsigned char red, unsigned char green, unsigned char blue);
	Vec3 sample(Vec2 coords) const;
private:
	int m_width;
	int m_height;
	unsigned char* m_colorBuffer;
};