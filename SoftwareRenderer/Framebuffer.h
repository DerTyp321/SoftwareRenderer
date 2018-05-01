#pragma once

class Framebuffer {
public:
	Framebuffer(int width, int height);
	~Framebuffer();
	void resize(int width, int height);
	int getWidth();
	int getHeight();
	float getDepth(int x, int y);
	void clear(int abgr);
	void setPixel(int x, int y, int abgr, float depth);
	int* getColorBuffer();
private:
	int m_width, m_height;
	int *m_colorBuffer;
	float *m_depthBuffer;
};