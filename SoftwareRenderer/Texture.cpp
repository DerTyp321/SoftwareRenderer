#include "Texture.h"

Texture::Texture(int width, int height) {
	m_width = width;
	m_height = height;
	m_colorBuffer = new int[m_width * m_height];
}

Texture::~Texture() {
	delete[] m_colorBuffer;
}

void Texture::setPixel(int x, int y, int abgr) {
	if (x < 0 || y < 0 || x >= m_width || y >= m_height)return;
	m_colorBuffer[x + y * m_width] = abgr;
}

Vec3 Texture::sample(Vec2 coords) const {
	int x = (int)(coords.x * (float)(m_width));
	int y = (int)(coords.y * (float)(m_height));
	if (x < 0) x = 0;
	else if (x >= m_width) x = m_width - 1;
	if (y < 0 )y = 0;
	else if (y >= m_height) y = m_height - 1;
	int sample = m_colorBuffer[x + y * m_width];
	return Vec3{
		(float)((sample) & 0xff) / 255.0f,
		(float)((sample >> 8) & 0xff) / 255.0f,
		(float)((sample >> 16) & 0xff) / 255.0f,
	};
}


