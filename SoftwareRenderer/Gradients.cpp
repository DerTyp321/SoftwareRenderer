#include "Gradients.h"

Gradients::Gradients(Vertex top, Vertex mid, Vertex bot) {
	float oneOverdX = 1.0f / (
		(mid.getPos().x - bot.getPos().x) *
		(top.getPos().y - bot.getPos().y) -
		(top.getPos().x - bot.getPos().x) *
		(mid.getPos().y - bot.getPos().y)
	);
	float oneOverdY = -oneOverdX;

	m_oneOverZ[0] = 1.0f / top.getPos().w;
	m_oneOverZ[1] =	1.0f / mid.getPos().w;
	m_oneOverZ[2] =	1.0f / bot.getPos().w;
	
	m_texCoords[0] = top.getTexCoords() * m_oneOverZ[0];
	m_texCoords[1] = mid.getTexCoords() * m_oneOverZ[1];
	m_texCoords[2] = bot.getTexCoords() * m_oneOverZ[2];

	m_depth[0] = top.getPos().z;
	m_depth[1] = mid.getPos().z;
	m_depth[2] = bot.getPos().z;

	m_oneOverZXStep = (
		(m_oneOverZ[1] - m_oneOverZ[2]) *
		(top.getPos().y - bot.getPos().y) -
		(m_oneOverZ[0] - m_oneOverZ[2]) *
		(mid.getPos().y - bot.getPos().y)
		) * oneOverdX;

	m_oneOverZYStep = (
		(m_oneOverZ[1] - m_oneOverZ[2]) *
		(top.getPos().x - bot.getPos().x) -
		(m_oneOverZ[0] - m_oneOverZ[2]) *
		(mid.getPos().x - bot.getPos().x)
		) * oneOverdY;

	m_texCoordsXStep = (
		(m_texCoords[1] - m_texCoords[2]) *
		(top.getPos().y - bot.getPos().y) -
		(m_texCoords[0] - m_texCoords[2]) *
		(mid.getPos().y - bot.getPos().y)
	) * oneOverdX;

	m_texCoordsYStep = (
		(m_texCoords[1] - m_texCoords[2]) *
		(top.getPos().x - bot.getPos().x) -
		(m_texCoords[0] - m_texCoords[2]) *
		(mid.getPos().x - bot.getPos().x)
	) * oneOverdY;

	m_depthXStep = (
		(m_depth[1] - m_depth[2]) *
		(top.getPos().y - bot.getPos().y) -
		(m_depth[0] - m_depth[2]) *
		(mid.getPos().y - bot.getPos().y)
		) * oneOverdX;

	m_depthYStep = (
		(m_depth[1] - m_depth[2]) *
		(top.getPos().x - bot.getPos().x) -
		(m_depth[0] - m_depth[2]) *
		(mid.getPos().x - bot.getPos().x)
		) * oneOverdY;
}

const Vec2& Gradients::getTexCoords(int index) {
	return m_texCoords[index];
}

const Vec2& Gradients::getTexCoordsXStep() {
	return m_texCoordsXStep;
}

const Vec2& Gradients::getTexCoordsYStep() {
	return m_texCoordsYStep;
}

float Gradients::getOneOverZ(int index) {
	return m_oneOverZ[index];
}

float Gradients::getOneOverZXStep() {
	return m_oneOverZXStep;
}

float Gradients::getOneOverZYStep() {
	return m_oneOverZYStep;
}

float Gradients::getDepth(int index) {
	return m_depth[index];
}

float Gradients::getDepthXStep() {
	return m_depthXStep;
}

float Gradients::getDepthYStep() {
	return m_depthYStep;
}
