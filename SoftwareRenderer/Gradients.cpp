#include "Gradients.h"

Gradients::Gradients(Vertex top, Vertex mid, Vertex bot) {
	m_texCoords[0] = top.getTexCoords();
	m_texCoords[1] = mid.getTexCoords();
	m_texCoords[2] = bot.getTexCoords();

	float oneOverdX = 1.0f / (
		(mid.getPos().x - bot.getPos().x) *
		(top.getPos().y - bot.getPos().y) -
		(top.getPos().x - bot.getPos().x) *
		(mid.getPos().y - bot.getPos().y)
	);
	float oneOverdY = -oneOverdX;
	
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
