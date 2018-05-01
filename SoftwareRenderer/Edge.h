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
	const Vec3& getColor();
private:
	int m_yStart;
	int m_yEnd;
	float m_xPos;
	float m_xStep;
	Vec3 m_color;
	Vec3 m_colorStep;
};