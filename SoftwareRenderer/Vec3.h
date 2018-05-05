#pragma once

struct Vec3 {
	Vec3();
	Vec3(float x, float y, float z);
	float x, y, z;
	Vec3& add(const Vec3& o);
	Vec3& sub(const Vec3& o);
	Vec3& mul(const Vec3& o);
	Vec3& mul(float f);

	Vec3& normalize();

	float len() const;

	Vec3 lerp(const Vec3& o, float amt);

	Vec3& operator+=(const Vec3& o);
	Vec3& operator-=(const Vec3& o);
	Vec3& operator*=(const Vec3& o);
	Vec3& operator*=(float o);
};

Vec3 add(const Vec3& a, const Vec3& b);
Vec3 sub(const Vec3& a, const Vec3& b);
Vec3 mul(const Vec3& a, const Vec3& b);
Vec3 mul(const Vec3& a, float f);

Vec3 normalize(const Vec3& a);
Vec3 cross(const Vec3& a, const Vec3& b);
float dot(const Vec3& a, const Vec3& b);

Vec3 operator+(const Vec3& a, const Vec3& b);
Vec3 operator-(const Vec3& a, const Vec3& b);
Vec3 operator*(const Vec3& a, const Vec3& b);
Vec3 operator*(const Vec3& a, float f);