#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b) {
	if (*(int*)a < *(int*)b) {
		return -1;
	}
	else if (*(int*)a == *(int*)b) {
		return 0;
	}
	else {
		return 1;
	}
}

int main(void) {
	int n, tmp, sum = 0;
	float leveltmp;

	scanf("%d", &n);

	if (n == 0) {
		printf("0"); return 0;
	}

	int* ary = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}

	qsort(ary, n, sizeof(int), compare);

	leveltmp = (float)n * 0.15;
	tmp = (int)round(leveltmp);

	for (int i = tmp; i < n - tmp; i++) {
		sum += ary[i];
	}

	float avg = (float)sum / (float)(n - 2 * tmp);
	int answer = (int)round(avg);
	printf("%d", answer);

	return 0;
}