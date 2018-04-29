#pragma once
#include <iostream>
#include <iomanip>
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include "Mat4.h"

#include <SDL.h>
#undef main

#define P_START Uint64 ptime = SDL_GetPerformanceCounter();
#define P_END std::cout <<  (double)(SDL_GetPerformanceCounter() - ptime) / (double)SDL_GetPerformanceFrequency() * 1000.0 << "ms" << std::endl;

void ioInit();

std::ostream& operator<<(std::ostream& os, const Vec2& v);

std::ostream& operator<<(std::ostream& os, const Vec3& v);

std::ostream& operator<<(std::ostream& os, const Vec4& v);

std::ostream& operator<<(std::ostream& os, const Mat4& m);