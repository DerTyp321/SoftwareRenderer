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

//Warning: set functions don't check bounds
void Framebuffer::setRGB(int x, int y, unsigned char red, unsigned char green, unsigned char blue) {
	m_colorBuffer[(x + y * m_width) * 3 + 0] = red;
	m_colorBuffer[(x + y * m_width) * 3 + 1] = green;
	m_colorBuffer[(x + y * m_width) * 3 + 2] = blue;
}

void Framebuffer::setScanbufferX(int y, int x, int side) {
	m_scanbuffer[side][y] = x;
}

int Framebuffer::getScanbufferStartX(int y) {
	return m_scanbuffer[0][y];
}

int Framebuffer::getScanbufferEndX(int y) {
	return m_scanbuffer[1][y];
}
unsigned char* Framebuffer::getColorBuffer() {
	return m_colorBuffer;
}