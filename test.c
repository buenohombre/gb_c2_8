#include "main.h"

//
// a  /\ b
//   /  \
// d \  / c
//    \/
static float testA(float x)
{
    return x - 1;
}

static float testB(float x)
{
    return -x + 7;
}

static float testC(float x)
{
    return x - 5;
}

static float testD(float x)
{
    return -x + 3;
}

void TestSquare()
{
    printf("Test (sum for square 2;1 4;3; 6;1 4;-1)\n");
    float eps = 0.001f;

    float xAB = FindRootChord(0, 10, eps, testA, testB);
    float xBC = FindRootChord(0, 10, eps, testB, testC);
    float xCD = FindRootChord(0, 10, eps, testC, testD);
    float xAD = FindRootChord(0, 10, eps, testA, testD);
    printf("Cross  A/B: %f\n", xAB);
    printf("Cross  B/C: %f\n", xBC);
    printf("Cross  C/D: %f\n", xCD);
    printf("Cross  A/D: %f\n", xAD);

    float sAD = CalcIntegralTrapeze(xAD, xAB, 1000, testA, testD);
    float sBC = CalcIntegralTrapeze(xAB, xBC, 1000, testB, testC);
    printf("Sum : %f\n", sAD + sBC);
}