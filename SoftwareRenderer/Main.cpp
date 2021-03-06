﻿#include <SDL.h>
#undef main

#include <iostream>

#include "DebugUtil.h"

#include "Window.h"
#include "Renderer.h"
#include "MathUtil.h"
#include "Texture.h"
#include "OBJLoader.h"

int main(int argc, char* argv[]) {
	ioInit();

	Window window("Main Window", 800, 600);
	Renderer renderer;

	Mat4 model;
	Mat4 view = Mat4::createTranslation(0.0f, 0.0f, 5.0f);
	Mat4 projection;
	uint32_t lastTime = 0;
	float delta = 0;
	float total = 0;

	//Mesh object = OBJMesh("res/man_highres.mesh").toIndexedMesh();
	//Mesh object = OBJMesh("res/man_lowres.mesh").toIndexedMesh();
	//Mesh object = OBJMesh("res/monkey.mesh").toIndexedMesh();
	//Mesh object = OBJMesh("res/monkey_smooth.mesh").toIndexedMesh();
	Mesh object = OBJMesh("res/monkey_highres.mesh").toIndexedMesh();

	Mesh triangle;
	triangle.addVertex(Vertex(Vec3(+0.0f, +1.0f, +0.0f), Vec2(0.5f, 0.0f), Vec3(0.0f, 0.0f, 0.0f)));
	triangle.addVertex(Vertex(Vec3(-1.0f, -1.0f, +0.0f), Vec2(0.0f, 1.0f), Vec3(0.0f, 0.0f, 0.0f)));
	triangle.addVertex(Vertex(Vec3(+1.0f, -1.0f, +0.0f), Vec2(1.0f, 1.0f), Vec3(0.0f, 0.0f, 0.0f)));
	triangle.addIndex(0);
	triangle.addIndex(1);
	triangle.addIndex(2);
	triangle.addIndex(2);
	triangle.addIndex(1);
	triangle.addIndex(0);

	//Texture tex("res/wood.bmp");
	//Texture tex("res/man.bmp");
	//Texture tex("res/uv_test.bmp");
	//Texture tex("res/logoQuadrat.bmp");
	Texture tex("res/monkey.bmp");

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
		model = Mat4::createRotation(0, total * 2.0f, 0);
		projection = Mat4::createProjection(1.0f, (float)window.getWidth() / (float)window.getHeight(), 0.1f, 100.0f);
		window.getFramebuffer().clear(0x333333);

		Mat4 modelview = view * model;
		renderer.renderMesh(window.getFramebuffer(), tex, object, projection * modelview, modelview, Vec3{ 1.0f, 0.0f, 0.0f });

		window.draw();

		lastTime = currentTime;

	}
}