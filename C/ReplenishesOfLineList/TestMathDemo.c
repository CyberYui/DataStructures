//TestMathDemo.c

#include <stdio.h>

_declspec (dllimport) float GetAdd(float a, float b);

int main(int agrc, char **argv)
{
	float result = GetAdd(2, 3);
	printf("result=%f\n", result);
	return 0;
}