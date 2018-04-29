#include "Vec2.h"
#include <cmath>

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

Vec2& Vec2::normalize() {
	float l = len();
	x /= l;
	y /= l;
	return *this;
}

float Vec2::len() const {
	return sqrt(x * x + y * y);
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

Vec2 normalize(const Vec2 & a) {
	float l = a.len();
	return Vec2{ a.x / l, a.y / l };
}

float cross(const Vec2& a, const Vec2& b) {
	return (a.x * b.y - a.y * b.x);
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