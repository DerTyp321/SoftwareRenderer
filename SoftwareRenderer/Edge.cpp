#include "Edge.h"

Edge::Edge(Vertex start, Vertex end) {
	m_yStart = (int)ceil(start.getPos().y);
	m_yEnd = (int)ceil(end.getPos().y);
	m_xStep = (end.getPos().x - start.getPos().x) / (end.getPos().y - start.getPos().y);
	m_xPos = start.getPos().x + ((float)m_yStart - start.getPos().y) * m_xStep;
}

void Edge::step() {
	m_xPos += m_xStep;
}

int Edge::getYStart() {
	return m_yStart;
}

int Edge::getYEnd() {
	return m_yEnd;
}

float Edge::getXPos() {
	return m_xPos;
}
