#include <stdio.h>

int main(void) {
	int n, sum = 0;
	char ary[100];
	int number;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf(" %c", &number);
		ary[i] = number;
		sum += ary[i]-'0';
	}
	printf("%d", sum);
	return 0;
}