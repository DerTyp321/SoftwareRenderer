#pragma once

class Framebuffer {
public:
	Framebuffer(int width, int height);
	~Framebuffer();
	void resize(int width, int height);
	int getWidth();
	int getHeight();
	float getDepth(int x, int y);
	void clear(unsigned char red, unsigned char green, unsigned char blue);
	void setPixel(int x, int y, unsigned char red, unsigned char green, unsigned char blue, float depth);
	unsigned char *getColorBuffer();
private:
	int m_width, m_height;
	unsigned char *m_colorBuffer;
	float *m_depthBuffer;
};