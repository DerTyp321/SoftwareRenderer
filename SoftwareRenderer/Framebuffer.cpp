#include "Framebuffer.h"
#include <limits>

Framebuffer::Framebuffer(int width, int height) {
	m_width = width;
	m_height = height;
	m_colorBuffer = new unsigned char[m_width * m_height * 3];
	m_depthBuffer = new float[m_width * m_height];
}

Framebuffer::~Framebuffer() {
	delete[] m_colorBuffer;
}

void Framebuffer::resize(int width, int height) {
	m_width = width;
	m_height = height;
	delete[] m_colorBuffer;
	m_colorBuffer = new unsigned char[m_width * m_height * 3];
	delete[] m_depthBuffer;
	m_depthBuffer = new float[m_width * m_height];
}

int Framebuffer::getWidth() {
	return m_width;
}

int Framebuffer::getHeight() {
	return m_height;
}

float Framebuffer::getDepth(int x, int y) {
	if (x < 0 || y < 0 || x >= m_width || y >= m_height)return 0.0f;
	return m_depthBuffer[x + y * m_width];
}

void Framebuffer::clear(unsigned char red, unsigned char green, unsigned char blue) {
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			setPixel(x, y, red, green, blue, std::numeric_limits<float>::max());
		}
	}
}

void Framebuffer::setPixel(int x, int y, unsigned char red, unsigned char green, unsigned char blue, float depth) {
	if (x < 0 || y < 0 || x >= m_width || y >= m_height)return;
	m_colorBuffer[(x + y * m_width) * 3 + 0] = red;
	m_colorBuffer[(x + y * m_width) * 3 + 1] = green;
	m_colorBuffer[(x + y * m_width) * 3 + 2] = blue;
	m_depthBuffer[x + y * m_width] = depth;
}

unsigned char* Framebuffer::getColorBuffer() {
	return m_colorBuffer;
}