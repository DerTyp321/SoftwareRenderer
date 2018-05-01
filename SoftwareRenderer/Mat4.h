#pragma once
#include "MathUtil.h"

struct Mat4 {
	float m[4][4];
	static Mat4 createIdentity();
	static Mat4 createRotation(float x, float y, float z);
	static Mat4 createTranslation(float x, float y, float z);
	static Mat4 createScale(float x, float y, float z);
	static Mat4 createProjection(float fov, float aspectRatio, float zNear, float zFar);
	static Mat4 createLookAt(Vec3 forward, Vec3 up);
};

Mat4 mul(const Mat4& a, const Mat4& b);
Mat4 operator*(const Mat4& a, const Mat4& b);

Vec4 mul(const Vec4& a, const Mat4& b);
Vec4 operator*(const Vec4& a, const Mat4& b);