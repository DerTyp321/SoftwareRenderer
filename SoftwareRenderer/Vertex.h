#pragma once
#include "MathUtil.h"

class Vertex {
public:
	Vertex(const Vec3& pos, const Vec2& texCoords, const Vec3& normal);
	void transformToScreen(const Mat4& mvp, int screenWidth, int screenHeight);
	bool compareY(const Vertex& o) const;
	bool handedness(const Vertex& a, const Vertex& b) const;
	bool isEqual(const Vertex& other) const;
	const Vec4& getPos() const;
	const Vec2& getTexCoords() const;
	const Vec4& getNormal() const;
private:
	Vec4 m_pos;
	Vec2 m_texCoords;
	Vec4 m_normal;
};