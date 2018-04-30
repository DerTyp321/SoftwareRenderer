#pragma once
#include <vector>
#include "Vec3.h"
#include "Vec4.h"

struct Vertex {
	Vec3 pos;
	Vec4 getPosVec4();
};

class Mesh {
public:
	void addVertex(Vertex vert);
	void addIndex(int i);
	std::vector<Vertex>& getVertices();
	std::vector<int>& getIndices();
private:
	std::vector<Vertex> m_vertices;
	std::vector<int> m_indices;
};