#include "main.h"
#include "args.h"
#include "homework.h"
#include "test.h"

static void PrintUsage()
{
    printf("Usage: \r\n");
    printf("-h: help\r\n");
    printf("-test: test square\r\n");
    printf("-w do homework\r\n");
}

void main(int argc, char **argv)
{
    ProgrammArg args[10];
    int keyCount = ParseArgs(argc, argv, args, sizeof(args) / sizeof(*args));
    if (keyCount < 1 || ContainKey(args, keyCount, "-h"))
    {
        PrintUsage();
    }
    else
    {
        while (1)
        {
            const ProgrammArg *arg = FindKey(args, keyCount, "-test");
            if (arg != NULL)
            {
                TestSquare();
                break;
            }
            arg = FindKey(args, keyCount, "-w");
            if (arg != NULL)
            {
                Homework();
                break;
            }

            PrintUsage();
            break;
        }
    }
}