#include <stdio.h>

int main(void)
{
	int N, Q;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		Q = N - i;
		while (Q != 0) {
			printf(" ");
			Q--;
		}
		for (int j = 1; j<=i; j++) {
			
			printf("*");
		}
		printf("\n");
	}


	return 0;
}
