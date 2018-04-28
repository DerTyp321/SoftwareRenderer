#include "Vec2.h"

Vec2 Vec2::add(Vec2 o) {
	x += o.x;
	y += o.y;
	return *this;
}

Vec2 Vec2::sub(Vec2 o) {
	x -= o.x;
	y -= o.y;
	return *this;
}

Vec2 Vec2::mul(Vec2 o) {
	x *= o.x;
	y *= o.y;
	return *this;
}

Vec2 Vec2::div(Vec2 o) {
	x /= o.x;
	y /= o.y;
	return *this;
}

Vec2 Vec2::add(float f) {
	x += f;
	y += f;
	return *this;
}

Vec2 Vec2::sub(float f) {
	x -= f;
	y -= f;
	return *this;
}

Vec2 Vec2::mul(float f) {
	x *= f;
	y *= f;
	return *this;
}

Vec2 Vec2::div(float f) {
	x /= f;
	y /= f;
	return *this;
}

Vec2& Vec2::operator+=(Vec2& o) {
	this->add(o);
	return *this;
}

Vec2& Vec2::operator-=(Vec2& o) {
	this->sub(o);
	return *this;
}

Vec2& Vec2::operator*=(Vec2& o) {
	this->mul(o);
	return *this;
}

Vec2& Vec2::operator/=(Vec2& o) {
	this->div(o);
	return *this;
}

Vec2& Vec2::operator+=(float f) {
	this->add(f);
	return *this;
}

Vec2& Vec2::operator-=(float f) {
	this->sub(f);
	return *this;
}

Vec2& Vec2::operator*=(float f) {
	this->mul(f);
	return *this;
}

Vec2& Vec2::operator/=(float f) {
	this->div(f);
	return *this;
}

Vec2 add(Vec2 a, Vec2 b) {
	return Vec2{ a.x + b.x, 
				 a.y + b.y};
}

Vec2 sub(Vec2 a, Vec2 b) {
	return Vec2{ a.x - b.x,
				 a.y - b.y };
}

Vec2 mul(Vec2 a, Vec2 b) {
	return Vec2{ a.x * b.x,
				 a.y * b.y };
}

Vec2 div(Vec2 a, Vec2 b) {
	return Vec2{ a.x / b.x,
				 a.y / b.y };
}

Vec2 add(Vec2 a, float f) {
	return Vec2{ a.x + f,
				 a.y + f };
}

Vec2 sub(Vec2 a, float f) {
	return Vec2{ a.x - f,
				 a.y - f };
}

Vec2 mul(Vec2 a, float f) {
	return Vec2{ a.x * f,
				 a.y * f };
}

Vec2 div(Vec2 a, float f) {
	return Vec2{ a.x / f,
				 a.y / f };
}

float cross(Vec2 a, Vec2 b) {
	return (a.x * b.y - b.x * a.y);
}

Vec2 operator+(Vec2 a, Vec2 b) {
	return add(a, b);
}

Vec2 operator-(Vec2 a, Vec2 b) {
	return sub(a, b);
}

Vec2 operator*(Vec2 a, Vec2 b) {
	return mul(a, b);
}

Vec2 operator/(Vec2 a, Vec2 b) {
	return div(a, b);
}

Vec2 operator+(Vec2 a, float f) {
	return add(a, f);
}

Vec2 operator-(Vec2 a, float f) {
	return sub(a, f);
}

Vec2 operator*(Vec2 a, float f) {
	return mul(a, f);
}

Vec2 operator/(Vec2 a, float f) {
	return div(a, f);
}
