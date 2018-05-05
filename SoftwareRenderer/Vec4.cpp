#include "Vec4.h"

Vec4::Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {
}

Vec4::Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w){
}

Vec4& Vec4::add(const Vec4& o) {
	x += o.x;
	y += o.y;
	z += o.z;
	w += o.w;
	return *this;
}

Vec4& Vec4::sub(const Vec4& o) {
	x -= o.x;
	y -= o.y;
	z -= o.z;
	w -= o.w;
	return *this;
}

Vec4& Vec4::mul(const Vec4& o) {
	x *= o.x;
	y *= o.y;
	z *= o.z;
	w *= o.w;
	return *this;
}

Vec4& Vec4::mul(float f) {
	x *= f;
	y *= f;
	z *= f;
	w *= f;
	return *this;
}

Vec4& Vec4::zDiv() {
	x /= w;
	y /= w;
	z /= w;
	return *this;
}

Vec3 Vec4::toVec3() const {
	return Vec3{x, y, z};
}

Vec4 Vec4::lerp(const Vec4 & o, float amt) {
	return *this + ((o - *this) * amt);
}

Vec4& Vec4::operator+=(const Vec4& o) {
	this->add(o);
	return *this;
}

Vec4& Vec4::operator-=(const Vec4& o) {
	this->sub(o);
	return *this;
}

Vec4& Vec4::operator*=(const Vec4& o) {
	this->mul(o);
	return *this;
}

Vec4& Vec4::operator*=(float f) {
	this->mul(f);
	return *this;
}

Vec4 add(const Vec4& a, const Vec4& b) {
	return Vec4{ a.x + b.x,
		a.y + b.y,
		a.z + b.z,
		a.w + b.w };
}

Vec4 sub(const Vec4& a, const Vec4& b) {
	return Vec4{ a.x - b.x,
		a.y - b.y,
		a.z - b.z,
		a.w - b.w };
}

Vec4 mul(const Vec4& a, const Vec4& b) {
	return Vec4{ a.x * b.x,
		a.y * b.y,
		a.z * b.z,
		a.w * b.w };
}

Vec4 mul(const Vec4& a, float f) {
	return Vec4{ a.x * f,
		a.y * f,
		a.z * f,
		a.w * f };
}

Vec4 zDiv(const Vec4& a) {
	return Vec4{ a.x / a.w,
		a.y / a.w,
		a.z / a.w,
		a.w};
}


Vec4 operator+(const Vec4& a, const Vec4& b) {
	return add(a, b);
}

Vec4 operator-(const Vec4& a, const Vec4& b) {
	return sub(a, b);
}

Vec4 operator*(const Vec4& a, const Vec4& b) {
	return mul(a, b);
}

Vec4 operator*(const Vec4& a, float f) {
	return mul(a, f);
}