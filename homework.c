#include "main.h"

// homework
static float f1(float x)
{
    return 0.6f * x + 3;
}

static float f2(float x)
{
    return (float)pow(x - 2, 3) - 1;
}

static float f3(float x)
{
    return 3.0f / x;
}

void Homework()
{
    printf("Homework: calc square for f1, f2, f3\n");

    float eps = 0.001f;

    float x1_f1f3 = FindRootDiv2(-8, 0, eps, f1, f3);
    printf("-> x1_f1f3 Div2: %f\n", x1_f1f3);
    float x2_f2f3 = FindRootDiv2(-1, 0, eps, f2, f3);
    printf("-> x2_f2f3 Div2: %f\n", x2_f2f3);
    float x3_f1f3 = FindRootDiv2(0, 5, eps, f1, f3);
    printf("-> x3_f1f3 Div2: %f\n", x3_f1f3);
    float x4_f2f3 = FindRootDiv2(0, 5, eps, f2, f3);
    printf("-> x4_f2f3 Div2: %f\n", x4_f2f3);

    float s1 = CalcIntegralTrapeze(x1_f1f3, x2_f2f3, 1000, f1, f3);
    float s2 = CalcIntegralTrapeze(x2_f2f3, x3_f1f3, 1000, f1, f2);
    float s3 = CalcIntegralTrapeze(x3_f1f3, x4_f2f3, 1000, f2, f3);
    printf("Sum f1,f2,f3: %f\n", s1 + s2 + s3);
}