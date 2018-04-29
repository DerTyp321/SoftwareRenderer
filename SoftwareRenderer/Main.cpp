#include <SDL.h>
#undef main

#include <iostream>

#include "Window.h"
#include "Renderer.h"
#include "Vec3.h"
#include "Mat4.h"


int main() {
	Window window("Main Window", 800, 600);
	Renderer renderer;
	SDL_Event e;
	int a = 10;
	Mat4 model = Mat4::createIdentity();
	Mat4 view = Mat4::createTranslation(0.0f, 0.0f, 0.0f);
	Mat4 projection = Mat4::createProjection(1.3f, (float)800 / (float)600, 0.1f, 100.0f);
	while (SDL_PollEvent(&e), e.type != SDL_QUIT) {
		switch (e.type) {
		case SDL_WINDOWEVENT:
			window.handleEvent(e.window);
			break;
		}
		renderer.renderTriangle(window.getFramebuffer(), Vec4{-0.5f, -0.5f, -1.0f, 1.0f}, Vec4{ 0.5f, -0.5f, -1.0f, 1.0f }, Vec4{ 0.0f, 0.5f, -1.0f, 1.0f }, model, view, projection, Vec3{1.0f, 0.5f, 0.5f});
		renderer.renderRect(window.getFramebuffer(), 100, 100, 100, 100, Vec3{ 0.0f, 0.5f, 0.2f });
		renderer.renderRect(window.getFramebuffer(), 200, 400, 50, 200, Vec3{ 0.5f, 0.0f, 1.0f });
		renderer.renderRect(window.getFramebuffer(), 200, 500, 100, 400, Vec3{ 1.0f, 1.0f, 1.0f });
		window.draw();
	}
}