#include <stdio.h>

int main(void) {
	int N;
	double ary[1001];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lf ", &ary[i]);
	}

	int max = 0;
	for (int i = 0; i < N; i++) {
		if (ary[i] > max) max = ary[i];
	}

	double sum = 0;

	for (int i = 0; i < N; i++) {
		ary[i] = (ary[i] / max) * 100;
		sum += ary[i];
	}

	printf("%.2lf", sum / (double)N);
	return 0;
}