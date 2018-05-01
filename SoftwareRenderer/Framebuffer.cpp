#include "Framebuffer.h"
#include <limits>

Framebuffer::Framebuffer(int width, int height) {
	m_width = width;
	m_height = height;
	m_colorBuffer = new int[m_width * m_height];
	m_depthBuffer = new float[m_width * m_height];
}

Framebuffer::~Framebuffer() {
	delete[] m_colorBuffer;
}

void Framebuffer::resize(int width, int height) {
	m_width = width;
	m_height = height;
	delete[] m_colorBuffer;
	m_colorBuffer = new int[m_width * m_height];
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

void Framebuffer::clear(int abgr) {
	float maxValue = std::numeric_limits<float>::max();
	int size = m_width * m_height;
	for (int i = 0; i < size; i++) {
		m_colorBuffer[i] = abgr;
		m_depthBuffer[i] = maxValue;
	}
}

void Framebuffer::setPixel(int x, int y, int abgr, float depth) {
	if (x < 0 || y < 0 || x >= m_width || y >= m_height)return;
	m_colorBuffer[x + y * m_width] = abgr;
	m_depthBuffer[x + y * m_width] = depth;
}

int* Framebuffer::getColorBuffer() {
	return m_colorBuffer;
}