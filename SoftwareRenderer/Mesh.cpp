#include "Mesh.h"

Vec4 Vertex::getPosVec4() {
	return Vec4{ pos.x, pos.y, pos.z, 1.0f };
}

void Mesh::addVertex(Vertex vert) {
	m_vertices.push_back(vert);
}

void Mesh::addIndex(int i) {
	m_indices.push_back(i);
}

std::vector<Vertex>& Mesh::getVertices() {
	return m_vertices;
}

std::vector<int>& Mesh::getIndices() {
	return m_indices;
}
