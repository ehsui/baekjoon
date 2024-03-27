#include <stdio.h>

int main(void) {
	int N;
	int ary[10002] = { 0 };
	int index;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &index);
		ary[index] += 1;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < ary[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}