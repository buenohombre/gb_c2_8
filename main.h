#ifndef C__USERS_DMITRY_SOURCE_REPOS_HOMEWORK_C2_8_MAIN_H_
#define C__USERS_DMITRY_SOURCE_REPOS_HOMEWORK_C2_8_MAIN_H_

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"
#include "math.h"

#define signF(x) (x > 0 ? 1 : 0)

typedef float (*function)(float);

float Zero(float x);
float FindRootChord(float xl, float xr, float eps, function f, function g);
float FindRootDiv2(float xl, float xr, float eps, function f, function g);
float CalcIntegralTrapeze(float xl, float xr, size_t n, function f, function g);

#endif // C__USERS_DMITRY_SOURCE_REPOS_HOMEWORK_C2_8_MAIN_H_

