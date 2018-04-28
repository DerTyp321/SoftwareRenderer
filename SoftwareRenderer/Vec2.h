#pragma once

struct Vec2 {
	float x, y;
	Vec2& add(const Vec2& o);
	Vec2& sub(const Vec2& o);
	Vec2& mul(const Vec2& o);
	Vec2& mul(float f);

	Vec2& operator+=(const Vec2& o);
	Vec2& operator-=(const Vec2& o);
	Vec2& operator*=(const Vec2& o);
	Vec2& operator*=(float o);
};

Vec2 add(const Vec2& a, const Vec2& b);
Vec2 sub(const Vec2& a, const Vec2& b);
Vec2 mul(const Vec2& a, const Vec2& b);
Vec2 mul(const Vec2& a, float f);

float cross(const Vec2& a, const Vec2& b);

Vec2 operator+(const Vec2& a, const Vec2& b);
Vec2 operator-(const Vec2& a, const Vec2& b);
Vec2 operator*(const Vec2& a, const Vec2& b);
Vec2 operator*(const Vec2& a, float f);