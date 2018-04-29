#include "Mat4.h"
#include <cmath>

Mat4 Mat4::createIdentity() {
	return Mat4{ {
		{1.0f, 0.0f, 0.0f , 0.0f},
		{0.0f, 1.0f, 0.0f , 0.0f},
		{0.0f, 0.0f, 1.0f , 0.0f},
		{0.0f, 0.0f, 0.0f , 1.0f}
	} };
}

Mat4 Mat4::createRotation(float x, float y, float z) {
	Mat4 rotX = createIdentity();
	Mat4 rotY = createIdentity();
	Mat4 rotZ = createIdentity();
	rotX.m[1][1] = cos(x);
	rotX.m[2][1] = sin(x);
	rotX.m[1][2] = -sin(x);
	rotX.m[2][2] = cos(x);

	rotY.m[0][0] = cos(y);
	rotY.m[2][0] = sin(y);
	rotY.m[0][2] = -sin(y);
	rotY.m[2][2] = cos(y);

	rotZ.m[0][0] = cos(z);
	rotZ.m[0][1] = -sin(z);
	rotZ.m[1][0] = sin(z);
	rotZ.m[1][1] = cos(z);

	return rotX * rotY * rotZ;
}

Mat4 Mat4::createTranslation(float x, float y, float z) {
	return Mat4{ {
		{ 1.0f, 0.0f, 0.0f , x    },
		{ 0.0f, 1.0f, 0.0f , y    },
		{ 0.0f, 0.0f, 1.0f , z    },
		{ 0.0f, 0.0f, 0.0f , 1.0f }
	} };
}

Mat4 Mat4::createScale(float x, float y, float z) {
	return Mat4{ {
		{ x   , 0.0f, 0.0f , 0.0f },
		{ 0.0f, y   , 0.0f , 0.0f },
		{ 0.0f, 0.0f, z    , 0.0f },
		{ 0.0f, 0.0f, 0.0f , 1.0f }
	} };

}

Mat4 Mat4::createProjection(float fov, float aspectRatio, float zNear, float zFar) {
	float tanHalfFov = tanf((fov) / 2.0f);
	float zRange = zNear - zFar;
	return Mat4{ {
		{ 1.0f / (tanHalfFov * aspectRatio), 0.0f             , 0.0f                     , 0.0f                      },
		{ 0.0f                             , 1.0f / tanHalfFov, 0.0f                     , 0.0f                      },
		{ 0.0f                             , 0.0f             , (-zNear - zFar) / zRange , 2 * zNear * zFar / zRange },
		{ 0.0f                             , 0.0f             , 1.0f                     , 0.0f                      }
	} };
}

Mat4 Mat4::createLookAt(Vec3 forward, Vec3 up) {
	forward.normalize();
	up.normalize();
	Vec3 right = cross(up, forward);
	return Mat4{ {
		{ right.x  , right.y  , right.z  , 0.0f },
		{ up.x     , up.y     , up.z     , 0.0f },
		{ forward.x, forward.y, forward.z, 0.0f },
		{ 0.0f     , 0.0f     , 0.0f     , 1.0f }
	} };
}

Mat4 mul(const Mat4 & a, const Mat4 & b) {
	Mat4 result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = a.m[i][0] * b.m[0][j]
				+ a.m[i][1] * b.m[1][j]
				+ a.m[i][2] * b.m[2][j]
				+ a.m[i][3] * b.m[3][j];
		}
	}
	return result;
}

Mat4 operator*(const Mat4 & a, const Mat4 & b) {
	return mul(a, b);
}

Vec4 mul(const Vec4 & a, const Mat4 & b) {
	Vec4 result;
	result.x = a.x * b.m[0][0] + a.y * b.m[0][1] + a.z * b.m[0][2] + a.w * b.m[0][3];
	result.y = a.x * b.m[1][0] + a.y * b.m[1][1] + a.z * b.m[1][2] + a.w * b.m[1][3];
	result.z = a.x * b.m[2][0] + a.y * b.m[2][1] + a.z * b.m[2][2] + a.w * b.m[2][3];
	result.w = a.x * b.m[3][0] + a.y * b.m[3][1] + a.z * b.m[3][2] + a.w * b.m[3][3];
	return result;
}

Vec4 operator*(const Vec4 & a, const Mat4 & b) {
	return mul(a, b);
}
