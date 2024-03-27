#include <stdio.h>

int main(void)
{
	int A, Q[10], q = 0;
	for (int i = 0; i < 10; i++) {
		int out = 0;
		scanf("%d", &A);
		Q[i] = A % 42;
		for (int j = 0; j < i; j++) {
			if (Q[j] == Q[i]) {
				out = 1;
				break;
			}
		}
		if (out == 0) q += 1;
	}

	printf("%d", q);
	return 0;
}