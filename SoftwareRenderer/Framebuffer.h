#pragma once

class Framebuffer {
public:
	Framebuffer(int width, int height);
	~Framebuffer();
	void resize(int width, int height);
	int getWidth();
	int getHeight();
	void setRGB(int x, int y, unsigned char red, unsigned char green, unsigned char blue);
	void setScanbufferStartX(int y, int xStart);
	void setScanbufferEndX(int y, int xEnd);
	int getScanbufferStartX(int y);
	int getScanbufferEndX(int y);
	unsigned char *getColorBuffer();
private:
	int m_width, m_height;
	unsigned char *m_colorBuffer;
	int* m_scanbuffer[2];
};