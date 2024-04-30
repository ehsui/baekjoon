#include <stdio.h>
#include <stdlib.h>

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

int search(int target, int start, int end, int ary[]) {

	while (start <= end) {
		int mid = (start + end) / 2;
		if (ary[mid] == target) return 1;
		else if (ary[mid] > target) {
			end = mid - 1;
		}
		else if (ary[mid] < target) {
			start = mid + 1;
		}
	}

	return 0;
}

int main(void) {
	int N, M, i;

	(void)scanf("%d", &N);
	int* number1 = (int*)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &number1[i]);
	}

	qsort(number1, N, sizeof(int), compare);

	(void)scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int number2;
		(void)scanf("%d", &number2);
		int check = search(number2, 0, N - 1, number1);
		printf("%d\n", check);
	}

	free(number1);
	return 0;
}