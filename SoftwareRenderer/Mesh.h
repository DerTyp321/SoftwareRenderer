#pragma once
#include <vector>
#include "MathUtil.h"
#include "Vertex.h"

class Mesh {
public:
	void addVertex(Vertex vert);
	void addIndex(int i);
	std::vector<Vertex>& getVertices();
	std::vector<int>& getIndices();
	int hasVertex(const Vertex& vert);
private:
	std::vector<Vertex> m_vertices;
	std::vector<int> m_indices;
};