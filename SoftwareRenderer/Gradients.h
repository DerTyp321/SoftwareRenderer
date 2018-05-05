#pragma once
#include "MathUtil.h"
#include "Vertex.h"


class Gradients {
public:
	Gradients(Vertex top, Vertex mid, Vertex bot);
	const Vec2& getTexCoords(int index);
	const Vec2& getTexCoordsXStep();
	const Vec2& getTexCoordsYStep();
	const Vec3& getNormal(int index);
	const Vec3& getNormalXStep();
	const Vec3& getNormalYStep();
	float getOneOverZ(int index);
	float getOneOverZXStep();
	float getOneOverZYStep();
	float getDepth(int index);
	float getDepthXStep();
	float getDepthYStep();
private:
	Vec2 m_texCoords[3];
	Vec2 m_texCoordsXStep;
	Vec2 m_texCoordsYStep;
	Vec3 m_normal[3];
	Vec3 m_normalXStep;
	Vec3 m_normalYStep;
	float m_oneOverZ[3];
	float m_oneOverZXStep;
	float m_oneOverZYStep;
	float m_depth[3];
	float m_depthXStep;
	float m_depthYStep;
};