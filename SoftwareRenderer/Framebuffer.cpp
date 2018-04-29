#include "Framebuffer.h"

Framebuffer::Framebuffer(int width, int height) {
	m_width = width;
	m_height = height;
	m_colorBuffer = new unsigned char[m_width * m_height * 3];
	m_scanbuffer[0] = new int[m_height];
	m_scanbuffer[1] = new int[m_height];
}

Framebuffer::~Framebuffer() {
	delete[] m_colorBuffer;
	delete[] m_scanbuffer[0];
	delete[] m_scanbuffer[1];
}

void Framebuffer::resize(int width, int height) {
	m_width = width;
	m_height = height;
	delete[] m_colorBuffer;
	m_colorBuffer = new unsigned char[width * height * 3];
	delete[] m_scanbuffer[0];
	delete[] m_scanbuffer[1];
	m_scanbuffer[0] = new int[m_height];
	m_scanbuffer[1] = new int[m_height];
}

int Framebuffer::getWidth() {
	return m_width;
}

int Framebuffer::getHeight() {
	return m_height;
}

void Framebuffer::clear(unsigned char red, unsigned char green, unsigned char blue) {
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			setRGB(x, y, red, green, blue);
		}
	}
}


void Framebuffer::setRGB(int x, int y, unsigned char red, unsigned char green, unsigned char blue) {
	if (x < 0 || y < 0 || x >= m_width || y >= m_height)return;
	m_colorBuffer[(x + y * m_width) * 3 + 0] = red;
	m_colorBuffer[(x + y * m_width) * 3 + 1] = green;
	m_colorBuffer[(x + y * m_width) * 3 + 2] = blue;
}

void Framebuffer::setScanbufferX(int y, int x, int side) {
	if (y < 0 || y >= m_height)return;
	if (x < 0) x = 0;
	if (x > m_width) x = m_width;
	m_scanbuffer[side][y] = x;
}

int Framebuffer::getScanbufferStartX(int y) {
	if (y < 0 || y >= m_height)return 0;
	return m_scanbuffer[0][y];
}

int Framebuffer::getScanbufferEndX(int y) {
	if (y < 0 || y >= m_height)return 0;
	return m_scanbuffer[1][y];
}
unsigned char* Framebuffer::getColorBuffer() {
	return m_colorBuffer;
}