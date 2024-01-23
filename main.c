#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"
#include "math.h"

typedef float (*function)(float);

float test1(float x)
{
    return x * x - 5;
}

float test2(float x)
{
    return x;
}

float FindRootChord(float xl, float xr, float eps, function f, function g)
{
    int stepCount = 0;
    while (fabs(xl - xr) > eps)
    {
        xl = xl - (f(xl) - g(xl)) * (xr - xl) / ((f(xr) - g(xr)) - (f(xl) - g(xl)));
        xr = xr - (f(xr) - g(xr)) * (xl - xr) / ((f(xl) - g(xl)) - (f(xr) - g(xr)));
        stepCount++;
    }
    printf("found root for %d steps", stepCount);

    return xl;
}

void main(int argc, char **argv)
{
    float xl = 0;
    float xr = 5;
    float eps = 0.001f;

    printf(" -> Chord: %f\n", FindRootChord(xl, xr, eps, test1, test2));
}