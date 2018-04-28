#include <SDL.h>
#undef main

#include <iostream>

#include "Window.h"
#include "Renderer.h"
#include "Vec3.h"


int main() {
	Window window("Main Window", 800, 600);
	Renderer renderer;
	SDL_Event e;
	int a = 10;
	while (SDL_PollEvent(&e), e.type != SDL_QUIT) {
		switch (e.type) {
		case SDL_WINDOWEVENT:
			window.handleEvent(e.window);
			break;
		}
		renderer.renderTriangle(window.getFramebuffer(), Vec2{234.0f, 345.0f }, Vec2{140.0f, 354.0f }, Vec2{134.0f, 124.0f }, Vec3{1.0f, 0.5f, 0.5f});
		renderer.renderRect(window.getFramebuffer(), 100, 100, 100, 100, Vec3{ 0.0f, 0.5f, 0.2f });
		renderer.renderRect(window.getFramebuffer(), 200, 400, 50, 200, Vec3{ 0.5f, 0.0f, 1.0f });
		renderer.renderRect(window.getFramebuffer(), 200, 500, 100, 400, Vec3{ 1.0f, 1.0f, 1.0f });
		window.draw();
	}
}