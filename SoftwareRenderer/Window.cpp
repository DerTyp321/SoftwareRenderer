#include "Window.h"
#include <iostream>


Window::Window(std::string title, int width, int height) {
	m_width = width;
	m_height = height;
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		exit(1);
	}
	m_window = SDL_CreateWindow(title.c_str(), 100, 100, m_width, m_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (m_window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_SOFTWARE);
	if (m_renderer == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, m_width, m_height);
	m_framebuffer = new Framebuffer(m_width, m_height);
}

Window::~Window() {
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	delete m_framebuffer;
	SDL_Quit();
}

void Window::draw() {

	SDL_UpdateTexture(m_texture, NULL, m_framebuffer->getColorBuffer(), m_width * 3 * sizeof(unsigned char));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopyEx(m_renderer, m_texture, NULL, NULL, 0, 0, SDL_FLIP_NONE);
	SDL_RenderPresent(m_renderer);
}

void Window::handleEvent(SDL_WindowEvent ev) {
	switch (ev.event) {
	case SDL_WINDOWEVENT_RESIZED:
		std::cout << ev.data1 << " " << ev.data2;
		m_width = ev.data1;
		m_height = ev.data2;
		SDL_DestroyTexture(m_texture);
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, m_width, m_height);
		m_framebuffer->resize(m_width, m_height);
		break;
	}
}

Framebuffer& Window::getFramebuffer() {
	return *m_framebuffer;
}