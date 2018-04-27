#include "Vec3.h"

Vec3 Vec3::add(Vec3 o) {
	x += o.x;
	y += o.y;
	z += o.z;
	return *this;
}

Vec3 Vec3::sub(Vec3 o) {
	x -= o.x;
	y -= o.y;
	z -= o.z;
	return *this;
}

Vec3 Vec3::mul(Vec3 o) {
	x *= o.x;
	y *= o.y;
	z *= o.z;
	return *this;
}

Vec3 Vec3::div(Vec3 o) {
	x /= o.x;
	y /= o.y;
	z /= o.z;
	return *this;
}

Vec3 Vec3::add(float f) {
	x += f;
	y += f;
	z += f;
	return *this;
}

Vec3 Vec3::sub(float f) {
	x -= f;
	y -= f;
	z -= f;
	return *this;
}

Vec3 Vec3::mul(float f) {
	x *= f;
	y *= f;
	z *= f;
	return *this;
}

Vec3 Vec3::div(float f) {
	x /= f;
	y /= f;
	z /= f;
	return *this;
}

Vec3& Vec3::operator+=(Vec3& o) {
	this->add(o);
	return *this;
}

Vec3& Vec3::operator-=(Vec3& o) {
	this->sub(o);
	return *this;
}

Vec3& Vec3::operator*=(Vec3& o) {
	this->mul(o);
	return *this;
}

Vec3& Vec3::operator/=(Vec3& o) {
	this->div(o);
	return *this;
}

Vec3& Vec3::operator+=(float f) {
	this->add(f);
	return *this;
}

Vec3& Vec3::operator-=(float f) {
	this->sub(f);
	return *this;
}

Vec3& Vec3::operator*=(float f) {
	this->mul(f);
	return *this;
}

Vec3& Vec3::operator/=(float f) {
	this->div(f);
	return *this;
}

Vec3 add(Vec3 a, Vec3 b) {
	return Vec3{ a.x + b.x, 
				 a.y + b.y,
				 a.z + b.z };
}

Vec3 sub(Vec3 a, Vec3 b) {
	return Vec3{ a.x - b.x,
				 a.y - b.y,
				 a.z - b.z };
}

Vec3 mul(Vec3 a, Vec3 b) {
	return Vec3{ a.x * b.x,
				 a.y * b.y,
				 a.z * b.z };
}

Vec3 div(Vec3 a, Vec3 b) {
	return Vec3{ a.x / b.x,
				 a.y / b.y,
				 a.z / b.z };
}

Vec3 add(Vec3 a, float f) {
	return Vec3{ a.x + f,
				 a.y + f,
				 a.z + f };
}

Vec3 sub(Vec3 a, float f) {
	return Vec3{ a.x - f,
				 a.y - f,
				 a.z - f};
}

Vec3 mul(Vec3 a, float f) {
	return Vec3{ a.x * f,
				 a.y * f,
				 a.z * f };
}

Vec3 div(Vec3 a, float f) {
	return Vec3{ a.x / f,
				 a.y / f,
				 a.z / f };
}

Vec3 operator+(Vec3 a, Vec3 b) {
	return add(a, b);
}

Vec3 operator-(Vec3 a, Vec3 b) {
	return sub(a, b);
}

Vec3 operator*(Vec3 a, Vec3 b) {
	return mul(a, b);
}

Vec3 operator/(Vec3 a, Vec3 b) {
	return div(a, b);
}

Vec3 operator+(Vec3 a, float f) {
	return add(a, f);
}

Vec3 operator-(Vec3 a, float f) {
	return sub(a, f);
}

Vec3 operator*(Vec3 a, float f) {
	return mul(a, f);
}

Vec3 operator/(Vec3 a, float f) {
	return div(a, f);
}
