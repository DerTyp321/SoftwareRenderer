#pragma once

struct Vec3 {
	float x, y, z;
	Vec3 add(Vec3 o);
	Vec3 sub(Vec3 o);
	Vec3 mul(Vec3 o);
	Vec3 div(Vec3 o);
	Vec3 add(float f);
	Vec3 sub(float f);
	Vec3 mul(float f);
	Vec3 div(float f);
	Vec3& operator+=(Vec3& o);
	Vec3& operator-=(Vec3& o);
	Vec3& operator*=(Vec3& o);
	Vec3& operator/=(Vec3& o);
	Vec3& operator+=(float o);
	Vec3& operator-=(float o);
	Vec3& operator*=(float o);
	Vec3& operator/=(float o);
};

Vec3 add(Vec3 a, Vec3 b);
Vec3 sub(Vec3 a, Vec3 b);
Vec3 mul(Vec3 a, Vec3 b);
Vec3 div(Vec3 a, Vec3 b);
Vec3 add(Vec3 a, float f);
Vec3 sub(Vec3 a, float f);
Vec3 mul(Vec3 a, float f);
Vec3 div(Vec3 a, float f);

Vec3 operator+(Vec3 a, Vec3 b);
Vec3 operator-(Vec3 a, Vec3 b);
Vec3 operator*(Vec3 a, Vec3 b);
Vec3 operator/(Vec3 a, Vec3 b);
Vec3 operator+(Vec3 a, float f);
Vec3 operator-(Vec3 a, float f);
Vec3 operator*(Vec3 a, float f);
Vec3 operator/(Vec3 a, float f);