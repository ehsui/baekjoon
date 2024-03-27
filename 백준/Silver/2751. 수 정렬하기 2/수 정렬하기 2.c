#include <stdio.h>
#include <stdlib.h>


int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main(void) {
	int N;

	scanf("%d", &N);
	int* ary = malloc(sizeof(int) * N);


	for (int i = 0; i < N; i++) {
		scanf("%d", &ary[i]);
	}
	

	qsort(ary, N, sizeof(int), compare);

	for (int i = 0; i < N; i++) {
		printf("%d\n", ary[i]);
	}

	free(ary);
	return 0;
}



