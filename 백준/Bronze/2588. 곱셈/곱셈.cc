#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int x, y, z1, z2, z3;
	scanf("%d", &x);
	scanf("%d", &y);
	z1 = ((y % 100) % 10) * x;
	z2 = (y % 100 - ((y % 100) % 10)) * x / 10;
	z3 = (y - y % 100) * x /100;

	printf("%d\n%d\n%d\n%d", z1, z2, z3, x * y);
	
	return 0;
}