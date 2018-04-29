#pragma once
#include <iostream>
#include <iomanip>
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include "Mat4.h"

void ioInit();

std::ostream& operator<<(std::ostream& os, const Vec2& v);

std::ostream& operator<<(std::ostream& os, const Vec3& v);

std::ostream& operator<<(std::ostream& os, const Vec4& v);

std::ostream& operator<<(std::ostream& os, const Mat4& m);