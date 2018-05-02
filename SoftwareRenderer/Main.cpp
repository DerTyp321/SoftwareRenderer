#include <SDL.h>
#undef main

#include <iostream>

#include "DebugUtil.h"

#include "Window.h"
#include "Renderer.h"
#include "MathUtil.h"
#include "Texture.h"

int main() {
	ioInit();

	Window window("Main Window", 800, 600);
	Renderer renderer;

	Mat4 model;
	Mat4 view = Mat4::createTranslation(0.0f, 0.0f, 5.0f);
	Mat4 projection;
	uint32_t lastTime = 0;
	float delta = 0;
	float total = 0;

	Mesh cube;
	cube.addVertex(Vertex(+1.0f, +1.0f, +1.0f, 0.0f, 0.0f));
	cube.addVertex(Vertex(+1.0f, +1.0f, -1.0f, 0.0f, 1.0f));
	cube.addVertex(Vertex(+1.0f, -1.0f, +1.0f, 1.0f, 0.0f));
	cube.addVertex(Vertex(+1.0f, -1.0f, -1.0f, 1.0f, 1.0f));
	cube.addVertex(Vertex(-1.0f, +1.0f, +1.0f, 0.0f, 0.0f));
	cube.addVertex(Vertex(-1.0f, +1.0f, -1.0f, 0.0f, 1.0f));
	cube.addVertex(Vertex(-1.0f, -1.0f, +1.0f, 1.0f, 0.0f));
	cube.addVertex(Vertex(-1.0f, -1.0f, -1.0f, 1.0f, 1.0f));

	cube.addIndex(0); cube.addIndex(1); cube.addIndex(2);		cube.addIndex(1); cube.addIndex(2); cube.addIndex(3);
	cube.addIndex(4); cube.addIndex(5); cube.addIndex(6);		cube.addIndex(5); cube.addIndex(6); cube.addIndex(7);
	cube.addIndex(0); cube.addIndex(1); cube.addIndex(4);		cube.addIndex(1); cube.addIndex(4); cube.addIndex(5);
	cube.addIndex(2); cube.addIndex(3); cube.addIndex(6);		cube.addIndex(3); cube.addIndex(6); cube.addIndex(7);
	cube.addIndex(0); cube.addIndex(2); cube.addIndex(4);		cube.addIndex(2); cube.addIndex(4); cube.addIndex(6);
	cube.addIndex(1); cube.addIndex(3); cube.addIndex(5);		cube.addIndex(3); cube.addIndex(5); cube.addIndex(7);

	Mesh triangle;
	triangle.addVertex(Vertex(+0.0f, +1.0f, +0.0f, 0.5f, 0.0f));
	triangle.addVertex(Vertex(-1.0f, -1.0f, +0.0f, 0.0f, 1.0f));
	triangle.addVertex(Vertex(+1.0f, -1.0f, +0.0f, 1.0f, 1.0f));
	triangle.addIndex(0);
	triangle.addIndex(1);
	triangle.addIndex(2);

	Texture tex("bild2.bmp");
	//for (int x = 0; x < 8; x++) {
	//	for (int y = 0; y < 8; y++) {
	//		tex.setPixel(x, y, x * 32 | y * 32 << 8 | 100 << 16);
	//	}
	//}

	SDL_Event e;
	while (SDL_PollEvent(&e), e.type != SDL_QUIT) {
		uint32_t currentTime = SDL_GetTicks();
		delta = (float)(currentTime - lastTime) * 0.001f;
		total += delta;
		switch (e.type) {
		case SDL_WINDOWEVENT:
			window.handleEvent(e.window);
			break;
		}
		model = Mat4::createRotation(total * 0.243f, total * 2.0f, total * 1.376f);
		projection = Mat4::createProjection(1.0f, (float)window.getWidth() / (float)window.getHeight(), 0.1f, 100.0f);
		window.getFramebuffer().clear(0x333333);

		renderer.renderMesh(window.getFramebuffer(), tex, cube, projection * view * model, Vec3{ 1.0f, 0.0f, 0.0f });

		window.draw();

		lastTime = currentTime;

	}
}