#pragma once

struct Vec2 {
	float x, y;
	Vec2 add(Vec2 o);
	Vec2 sub(Vec2 o);
	Vec2 mul(Vec2 o);
	Vec2 div(Vec2 o);
	Vec2 add(float f);
	Vec2 sub(float f);
	Vec2 mul(float f);
	Vec2 div(float f);
	Vec2& operator+=(Vec2& o);
	Vec2& operator-=(Vec2& o);
	Vec2& operator*=(Vec2& o);
	Vec2& operator/=(Vec2& o);
	Vec2& operator+=(float o);
	Vec2& operator-=(float o);
	Vec2& operator*=(float o);
	Vec2& operator/=(float o);
};

Vec2 add(Vec2 a, Vec2 b);
Vec2 sub(Vec2 a, Vec2 b);
Vec2 mul(Vec2 a, Vec2 b);
Vec2 div(Vec2 a, Vec2 b);
Vec2 add(Vec2 a, float f);
Vec2 sub(Vec2 a, float f);
Vec2 mul(Vec2 a, float f);
Vec2 div(Vec2 a, float f);

Vec2 operator+(Vec2 a, Vec2 b);
Vec2 operator-(Vec2 a, Vec2 b);
Vec2 operator*(Vec2 a, Vec2 b);
Vec2 operator/(Vec2 a, Vec2 b);
Vec2 operator+(Vec2 a, float f);
Vec2 operator-(Vec2 a, float f);
Vec2 operator*(Vec2 a, float f);
Vec2 operator/(Vec2 a, float f);