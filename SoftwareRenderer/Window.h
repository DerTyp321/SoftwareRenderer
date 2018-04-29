#pragma once
#include <string>
#include <SDL.h>
#include "Framebuffer.h"

class Window {
public:
	Window(std::string title, int width, int height);
	~Window();
	void draw();
	void handleEvent(SDL_WindowEvent ev);
	int getWidth();
	int getHeight();
	Framebuffer& getFramebuffer();
private:
	int m_width, m_height;
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Framebuffer* m_framebuffer;
};
