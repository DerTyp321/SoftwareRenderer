#pragma once

class Framebuffer {
public:
	Framebuffer(int width, int height);
	~Framebuffer();
	void resize(int width, int height);
	int getWidth();
	int getHeight();
	void clear(unsigned char red, unsigned char green, unsigned char blue);
	void setRGB(int x, int y, unsigned char red, unsigned char green, unsigned char blue);
	unsigned char *getColorBuffer();
private:
	int m_width, m_height;
	unsigned char *m_colorBuffer;
};