#pragma once
#include "MathUtil.h"

class Vertex {
public:
	Vertex(float x, float y, float z, float texX, float texY);
	void transformToScreen(const Mat4& mvp, int screenWidth, int screenHeight);
	bool compareY(const Vertex& o) const;
	bool handedness(const Vertex& a, const Vertex& b) const;
	const Vec4& getPos() const;
	const Vec2& getTexCoords() const;
private:
	Vec4 m_pos;
	Vec2 m_texCoords;
};