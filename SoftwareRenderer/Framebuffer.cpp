#include "Framebuffer.h"

Framebuffer::Framebuffer(int width, int height) {
	m_width = width;
	m_height = height;
	m_colorBuffer = new unsigned char[width * height * 3];
	m_scanbuffer[0] = new int[m_height];
	m_scanbuffer[1] = new int[m_height];
}

Framebuffer::~Framebuffer() {
	delete[] m_colorBuffer;
	delete[] m_scanbuffer[0];
	delete[] m_scanbuffer[1];
}

void Framebuffer::resize(int width, int height) {
	delete[] m_colorBuffer;
	m_width = width;
	m_height = height;
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

unsigned char* Framebuffer::getColorBuffer() {
	return m_colorBuffer;
}