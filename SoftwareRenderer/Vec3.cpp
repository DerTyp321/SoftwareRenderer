#include "Vec3.h"
#include <cmath>

Vec3& Vec3::add(const Vec3& o) {
	x += o.x;
	y += o.y;
	z += o.z;
	return *this;
}

Vec3& Vec3::sub(const Vec3& o) {
	x -= o.x;
	y -= o.y;
	z -= o.z;
	return *this;
}

Vec3& Vec3::mul(const Vec3& o) {
	x *= o.x;
	y *= o.y;
	z *= o.z;
	return *this;
}

Vec3& Vec3::mul(float f) {
	x *= f;
	y *= f;
	z *= f;
	return *this;
}

Vec3& Vec3::normalize() {
	float l = len();
	x /= l;
	y /= l;
	z /= l;
	return *this;
}

float Vec3::len() const {
	return sqrt(x * x + y * y + z * z);
}

Vec3& Vec3::operator+=(const Vec3& o) {
	this->add(o);
	return *this;
}

Vec3& Vec3::operator-=(const Vec3& o) {
	this->sub(o);
	return *this;
}

Vec3& Vec3::operator*=(const Vec3& o) {
	this->mul(o);
	return *this;
}

Vec3& Vec3::operator*=(float f) {
	this->mul(f);
	return *this;
}

Vec3 add(const Vec3& a, const Vec3& b) {
	return Vec3{ a.x + b.x,
		a.y + b.y,
		a.z + b.z};
}

Vec3 sub(const Vec3& a, const Vec3& b) {
	return Vec3{ a.x - b.x,
		a.y - b.y,
		a.z - b.z};
}

Vec3 mul(const Vec3& a, const Vec3& b) {
	return Vec3{ a.x * b.x,
		a.y * b.y,
		a.z * b.z};
}

Vec3 mul(const Vec3& a, float f) {
	return Vec3{ a.x * f,
		a.y * f,
		a.z * f};
}

Vec3 normalize(const Vec3 & a) {
	float l = a.len();
	return Vec3{a.x / l, a.y / l, a.z / l};
}

Vec3 cross(const Vec3& a, const Vec3& b) {
	return Vec3{
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	};
}

Vec3 operator+(const Vec3& a, const Vec3& b) {
	return add(a, b);
}

Vec3 operator-(const Vec3& a, const Vec3& b) {
	return sub(a, b);
}

Vec3 operator*(const Vec3& a, const Vec3& b) {
	return mul(a, b);
}

Vec3 operator*(const Vec3& a, float f) {
	return mul(a, f);
}