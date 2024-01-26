#include "main.h"

static float CheckLeftRange(float xl, float xr, float eps, function f, function g)
{
    float diffL = f(xl) - g(xl);
    while (isinf(diffL))
    {
        xl += eps;
        if (xl >= xr)
        {
            return NAN;
        }

        diffL = f(xl) - g(xl);
    }

    return xl;
}

static float CheckRightRange(float xl, float xr, float eps, function f, function g)
{
    float diffR = f(xr) - g(xr);
    while (isinf(diffR))
    {
        xr -= eps;
        if (xr <= xl)
        {
            return NAN;
        }

        diffR = f(xl) - g(xl);
    }

    return xr;
}

float Zero(float x)
{
    return 0;
}

float FindRootChord(float xl, float xr, float eps, function f, function g)
{
    int stepCount = 0;
    float prevDiff = (float)fabs(xl - xr) + eps;

    while (fabs(xl - xr) > eps)
    {
        if (fabs(xl - xr) > prevDiff)
        {
            break;
        }
        else
        {
            prevDiff = (float)fabs(xl - xr);
        }

        xl = xl - (f(xl) - g(xl)) * (xr - xl) / ((f(xr) - g(xr)) - (f(xl) - g(xl)));
        xr = xr - (f(xr) - g(xr)) * (xl - xr) / ((f(xl) - g(xl)) - (f(xr) - g(xr)));
        stepCount++;
    }
    // printf("found root for %d steps", stepCount);

    if (fabs(xl - xr) < eps)
    {
        return xl;
    }

    return NAN;
}

float FindRootDiv2(float xl, float xr, float eps, function f, function g)
{
    int stepcount = 0;
    float result = NAN;

    while (fabs(xr - xl) > eps)
    {
        stepcount++;
        xl = CheckLeftRange(xl, xr, eps, f, g);
        if (xl != xl)
        {
            break;
        }

        xr = CheckRightRange(xl, xr, eps, f, g);
        if (xr != xr)
        {
            break;
        }

        float xm = CheckRightRange(xl, (xl + xr) / 2.0f, eps, f, g);
        if (xm != xm)
        {
            break;
        }

        float diffL = f(xl) - g(xl);
        float diffR = f(xr) - g(xr);
        float diffM = f(xm) - g(xm);

        if (fabs(diffR) < (eps / 10))
        {
            // printf("Find root for %d steps", stepcount);
            result = xr;
            break;
        }
        if (fabs(diffL) < (eps / 10))
        {
            // printf("Find root for %d steps", stepcount);
            result = xl;
            break;
        }
        if (stepcount > 1000)
        {
            break;
        }

        if (signF(diffR) != signF(diffM))
        {
            xl = xm;
        }
        else
        {
            xr = xm;
        }
    }

    result = (xl + xr) / 2;

    printf("Find root for %d steps", stepcount); // статистика
    return result;
}

float CalcIntegralTrapeze(float xl, float xr, size_t n, function f, function g)
{
    float sum = 0;
    float h = (xr - xl) / n;
    for (float x = xl; x < xr - h; x += h)
    {
        sum += (float)fabs(f(x) - g(x)) + (float)fabs(f(x + h) - g(x + h));
    }
    return sum * 0.5f * h;
}
