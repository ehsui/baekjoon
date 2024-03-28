#include <stdio.h>

int main(void)
{
	int x, result;
	scanf("%d", &x);
	result = ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0));
	printf("%d", result);
	return 0;
}