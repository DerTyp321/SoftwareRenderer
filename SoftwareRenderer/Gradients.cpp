#include "Gradients.h"

Gradients::Gradients(Vertex top, Vertex mid, Vertex bot) {
	m_color[0] = top.getColor();
	m_color[1] = mid.getColor();
	m_color[2] = bot.getColor();

	float oneOverdX = 1.0f / (
		(mid.getPos().x - bot.getPos().x) *
		(top.getPos().y - bot.getPos().y) -
		(top.getPos().x - bot.getPos().x) *
		(mid.getPos().y - bot.getPos().y)
	);
	float oneOverdY = -oneOverdX;
	
	m_colorXStep = (
		(m_color[1] - m_color[2]) *
		(top.getPos().y - bot.getPos().y) -
		(m_color[0] - m_color[2]) *
		(mid.getPos().y - bot.getPos().y)
	) * oneOverdX;

	m_colorYStep = (
		(m_color[1] - m_color[2]) *
		(top.getPos().x - bot.getPos().x) -
		(m_color[0] - m_color[2]) *
		(mid.getPos().x - bot.getPos().x)
	) * oneOverdY;
}

const Vec3& Gradients::getColor(int index) {
	return m_color[index];
}

const Vec3& Gradients::getColorXStep() {
	return m_colorXStep;
}

const Vec3& Gradients::getColorYStep() {
	return m_colorYStep;
}
