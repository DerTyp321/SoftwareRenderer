#include "Vertex.h"

Vertex::Vertex(float x, float y, float z) {
	m_pos = Vec4{ x, y, z, 1.0f };
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

bool Vertex::handedness(const Vertex & a, const Vertex & b) const {
	Vec2 toA{ a.getPos().x - m_pos.x, a.getPos().y - m_pos.y };
	Vec2 toB{ b.getPos().x - m_pos.x, b.getPos().y - m_pos.y };
	return cross(toA, toB) >= 0.0f;
}

const Vec4& Vertex::getPos() const {
	return m_pos;
}