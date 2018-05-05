#include "Vertex.h"

Vertex::Vertex(const Vec3& pos, const Vec2& texCoords, const Vec3& normal) {
	m_pos = Vec4{ pos.x, pos.y, pos.z, 1.0f };
	m_texCoords = Vec2{ pos.x, pos.y};
	m_normal = Vec4{ pos.x, pos.y, pos.z, 0.0f};
}

void Vertex::transformToScreen(const Mat4& mvp, int screenWidth, int screenHeight) {
	m_pos = m_pos * mvp;
	m_pos.zDiv();
	m_pos = Vec4{
		(m_pos.x + 1.0f) * 0.5f * (float)screenWidth,
		(m_pos.y + 1.0f) * 0.5f * (float)screenHeight,
		m_pos.z, m_pos.w
	};
}

bool Vertex::compareY(const Vertex & o) const {
	return m_pos.y > o.m_pos.y;
}

bool Vertex::isEqual(const Vertex& other) const {
	return m_pos.x == other.m_pos.x 
		&& m_pos.y == other.m_pos.y 
		&& m_pos.z == other.m_pos.z 
		&& m_texCoords.x == other.m_texCoords.x 
		&& m_texCoords.y == other.m_texCoords.y
		&& m_normal.x == other.m_normal.x
		&& m_normal.y == other.m_normal.y
		&& m_normal.z == other.m_normal.z;
}

bool Vertex::handedness(const Vertex & a, const Vertex & b) const {
	Vec2 toA{ a.getPos().x - m_pos.x, a.getPos().y - m_pos.y };
	Vec2 toB{ b.getPos().x - m_pos.x, b.getPos().y - m_pos.y };
	return cross(toA, toB) >= 0.0f;
}

const Vec4& Vertex::getPos() const {
	return m_pos;
}

const Vec2& Vertex::getTexCoords() const {
	return m_texCoords;
}

const Vec4& Vertex::getNormal() const {
	return m_normal;
}
