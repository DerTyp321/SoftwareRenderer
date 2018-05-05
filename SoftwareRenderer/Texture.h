#pragma once
#include "MathUtil.h"
#include <iostream>

class Texture {
public:
	Texture(int width, int height);
	Texture(std::string path);
	~Texture();
	void setPixel(int x, int y, int abgr);
	void flipY();
	Vec3 sample(Vec2 coords) const;
private:
	int m_width;
	int m_height;
	int* m_colorBuffer;
};