#include "DebugUtil.h"

void ioInit() {
	std::cout << std::fixed << std::setprecision(3);
}

std::ostream& operator<<(std::ostream& os, const Vec2& v) {
	return os << "Vec2{ " << v.x << " , " << v.y << " }" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Vec3& v) {
	return os << "Vec3{ " << v.x << " , " << v.y << " , " << v.z << " }" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Vec4& v) {
	return os << "Vec4{ " << v.x << " , " << v.y << " , " << v.z << " , " << v.w << " }" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Mat4& m) {
	return os
		<< "Mat4{ \t" << m.m[0][0] << ", \t" << m.m[0][1] << ", \t" << m.m[0][2] << ", \t" << m.m[0][3] << " }" << std::endl
		<< "    { \t" << m.m[1][0] << ", \t" << m.m[1][1] << ", \t" << m.m[1][2] << ", \t" << m.m[1][3] << " }" << std::endl
		<< "    { \t" << m.m[2][0] << ", \t" << m.m[2][1] << ", \t" << m.m[2][2] << ", \t" << m.m[2][3] << " }" << std::endl
		<< "    { \t" << m.m[3][0] << ", \t" << m.m[3][1] << ", \t" << m.m[3][2] << ", \t" << m.m[3][3] << " }" << std::endl;
}