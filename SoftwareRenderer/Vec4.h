#pragma once

struct Vec4 {
	float x, y, z, w;
	Vec4& add(const Vec4& o);
	Vec4& sub(const Vec4& o);
	Vec4& mul(const Vec4& o);
	Vec4& mul(float f);
	
	Vec4& zDiv();

	Vec4& operator+=(const Vec4& o);
	Vec4& operator-=(const Vec4& o);
	Vec4& operator*=(const Vec4& o);
	Vec4& operator*=(float o);
};

Vec4 add(const Vec4& a, const Vec4& b);
Vec4 sub(const Vec4& a, const Vec4& b);
Vec4 mul(const Vec4& a, const Vec4& b);
Vec4 mul(const Vec4& a, float f);

Vec4 zDiv(const Vec4& a);

Vec4 operator+(const Vec4& a, const Vec4& b);
Vec4 operator-(const Vec4& a, const Vec4& b);
Vec4 operator*(const Vec4& a, const Vec4& b);
Vec4 operator*(const Vec4& a, float f);