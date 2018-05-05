#pragma once
#include "Mesh.h"
#include "Gradients.h"

class Edge {
public:
	Edge(Gradients gradients, Vertex start, Vertex end, int startIndex);
	void step();
	int getYStart();
	int getYEnd();
	float getXPos();
	const Vec2& getTexCoords();
	const Vec3& getNormal();
	float getOneOverZ();
	float getDepth();
private:
	int m_yStart;
	int m_yEnd;
	float m_xPos;
	float m_xStep;
	Vec2 m_texCoords;
	Vec2 m_texCoordsStep;
	Vec3 m_normal;
	Vec3 m_normalStep;
	float m_oneOverZ;
	float m_oneOverZStep;
	float m_depth;
	float m_depthStep;
};