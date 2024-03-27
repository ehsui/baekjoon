#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < i+1; j++) printf("*");
		printf("\n");
	}

	return 0;
}