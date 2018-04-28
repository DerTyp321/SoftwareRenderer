#include "Vec2.h"

Vec2& Vec2::add(const Vec2& o) {
	x += o.x;
	y += o.y;
	return *this;
}

Vec2& Vec2::sub(const Vec2& o) {
	x -= o.x;
	y -= o.y;
	return *this;
}

Vec2& Vec2::mul(const Vec2& o) {
	x *= o.x;
	y *= o.y;
	return *this;
}

Vec2& Vec2::mul(float f) {
	x *= f;
	y *= f;
	return *this;
}

Vec2& Vec2::operator+=(const Vec2& o) {
	this->add(o);
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& o) {
	this->sub(o);
	return *this;
}

Vec2& Vec2::operator*=(const Vec2& o) {
	this->mul(o);
	return *this;
}

Vec2& Vec2::operator*=(float f) {
	this->mul(f);
	return *this;
}

Vec2 add(const Vec2& a, const Vec2& b) {
	return Vec2{ a.x + b.x, 
				 a.y + b.y};
}

Vec2 sub(const Vec2& a, const Vec2& b) {
	return Vec2{ a.x - b.x,
				 a.y - b.y };
}

Vec2 mul(const Vec2& a, const Vec2& b) {
	return Vec2{ a.x * b.x,
				 a.y * b.y };
}

Vec2 mul(const Vec2& a, float f) {
	return Vec2{ a.x * f,
				 a.y * f };
}

float cross(const Vec2& a, const Vec2& b) {
	return (a.x * b.y - b.x * a.y);
}

Vec2 operator+(const Vec2& a, const Vec2& b) {
	return add(a, b);
}

Vec2 operator-(const Vec2& a, const Vec2& b) {
	return sub(a, b);
}

Vec2 operator*(const Vec2& a, const Vec2& b) {
	return mul(a, b);
}

Vec2 operator*(const Vec2& a, float f) {
	return mul(a, f);
}