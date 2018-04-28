#pragma once

class Framebuffer {
public:
	Framebuffer(int width, int height);
	~Framebuffer();
	void resize(int width, int height);
	int getWidth();
	int getHeight();
	void setR(int x, int y, unsigned char red);
	void setG(int x, int y, unsigned char green);
	void setB(int x, int y, unsigned char blue);
	unsigned char *getColorBuffer();
private:
	int m_width, m_height;
	unsigned char *m_colorBuffer;
	int* m_scanbuffer[2];
};