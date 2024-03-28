#include <stdio.h>

int main(void)
{
	int A, B, C, ans, ary[10] = { 0, }, num;
	scanf("%d\n%d\n%d", &A, &B, &C);

	ans = A * B * C;
	while (1) {
		num = ans % 10;
		ans /= 10;

		for (int i = 0; i < 10; i++) {
			if (num == i) {
				ary[i] += 1;
			}
		}

		if ((ans / 10) < 1) {
			ary[ans] += 1;
			break;
		}
	}

	for(int i = 0; i < 10; i++) {
		printf("%d\n", ary[i]);
	}

	return 0;
}
