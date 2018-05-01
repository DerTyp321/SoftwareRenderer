#pragma once
#include "MathUtil.h"
#include "Vertex.h"


class Gradients {
public:
	Gradients(Vertex top, Vertex mid, Vertex bot);
	const Vec3& getColor(int index);
	const Vec3& getColorXStep();
	const Vec3& getColorYStep();
private:
	Vec3 m_color[3]{};
	Vec3 m_colorXStep;
	Vec3 m_colorYStep;
	
};