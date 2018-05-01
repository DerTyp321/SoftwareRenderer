#pragma once
#include "MathUtil.h"
#include "Vertex.h"


class Gradients {
public:
	Gradients(Vertex top, Vertex mid, Vertex bot);
	const Vec2& getTexCoords(int index);
	const Vec2& getTexCoordsXStep();
	const Vec2& getTexCoordsYStep();
	float getOneOverZ(int index);
	float getOneOverZXStep();
	float getOneOverZYStep();
	float getDepth(int index);
	float getDepthXStep();
	float getDepthYStep();
private:
	Vec2 m_texCoords[3]{};
	Vec2 m_texCoordsXStep;
	Vec2 m_texCoordsYStep;
	float m_oneOverZ[3];
	float m_oneOverZXStep;
	float m_oneOverZYStep;
	float m_depth[3];
	float m_depthXStep;
	float m_depthYStep;
};