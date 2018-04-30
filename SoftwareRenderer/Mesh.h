#pragma once
#include <vector>
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include "Mat4.h"

class Vertex {
public:
	Vertex(float x, float y, float z);
	void transformToScreen(const Mat4& mvp, int screenWidth, int screenHeight);
	bool compareY(const Vertex& o) const;
	bool handedness(const Vertex& a, const Vertex& b) const;
	const Vec4& getPos() const;
private:
	Vec4 m_pos;
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