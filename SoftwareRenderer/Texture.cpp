#include "Texture.h"

Texture::Texture(int width, int height) {
	m_width = width;
	m_height = height;
	m_colorBuffer = new unsigned char[m_width * m_height * 3];
}

Texture::~Texture() {
	delete[] m_colorBuffer;
}

void Texture::setPixel(int x, int y, unsigned char red, unsigned char green, unsigned char blue) {
	if (x < 0 || y < 0 || x >= m_width || y >= m_height)return;
	m_colorBuffer[(x + y * m_width) * 3 + 0] = red;
	m_colorBuffer[(x + y * m_width) * 3 + 1] = green;
	m_colorBuffer[(x + y * m_width) * 3 + 2] = blue;
}

Vec3 Texture::sample(Vec2 coords) const {
	int x = (int)(coords.x * (float)(m_width));
	int y = (int)(coords.y * (float)(m_height));
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (x >= m_width) x = m_width - 1;
	if (y >= m_height) y = m_height - 1;
	return Vec3{ 
		(float)m_colorBuffer[(x + y * m_width) * 3 + 0] / 255.0f,
		(float)m_colorBuffer[(x + y * m_width) * 3 + 1] / 255.0f,
		(float)m_colorBuffer[(x + y * m_width) * 3 + 2] / 255.0f
	};
}


