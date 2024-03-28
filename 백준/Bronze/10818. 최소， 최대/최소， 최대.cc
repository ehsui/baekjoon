#include <stdio.h>
int ary[1000000];

int main(void) {
	int num, n, max, min;

	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}

	max = ary[0], min = ary[0];

	for (int x = 1; x < num; x++) {
		if (ary[x] > max) max = ary[x];
		if (ary[x] < min) min = ary[x];
	}

	printf("%d %d", min, max);

	return 0;
}