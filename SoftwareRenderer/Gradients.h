#pragma once
#include "MathUtil.h"
#include "Vertex.h"


class Gradients {
public:
	Gradients(Vertex top, Vertex mid, Vertex bot);
	const Vec2& getTexCoords(int index);
	const Vec2& getTexCoordsXStep();
	const Vec2& getTexCoordsYStep();
private:
	Vec2 m_texCoords[3]{};
	Vec2 m_texCoordsXStep;
	Vec2 m_texCoordsYStep;
	
};