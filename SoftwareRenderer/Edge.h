#pragma once
#include "Mesh.h"

class Edge {
public:
	Edge(Vertex start, Vertex end);
	void step();
	int getYStart();
	int getYEnd();
	float getXPos();
private:
	int m_yStart;
	int m_yEnd;
	float m_xPos;
	float m_xStep;
};