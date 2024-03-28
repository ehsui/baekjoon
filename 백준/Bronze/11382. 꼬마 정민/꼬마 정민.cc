#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	long long x, y, z;
	scanf("%lld %lld %lld", &x, &y, &z);

	printf("%lld", x + y + z);
	
	return 0;
}