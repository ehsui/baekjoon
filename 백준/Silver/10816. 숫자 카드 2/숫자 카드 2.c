#include <stdio.h>
#include <stdlib.h>
#define SIZE 500000
int arr1[SIZE], arr2[SIZE];
int arr3[SIZE] = { 0 };

int compare(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;
	if (n1 < n2) return -1;
	else if (n1 > n2) return 1;
	else return 0;
}

int binary_search_start(int *array,int target,int start,int end) {
	if (start > end) return 10000001;
	int mid = (start + end) / 2;

	if (array[mid] == target) {
		if (mid - 1 < 0 || array[mid - 1] != target) return mid;
		else return binary_search_start(array, target, start, mid - 1);
	}
	else if (array[mid] > target) return binary_search_start(array, target, start, mid - 1);
	else return binary_search_start(array, target, mid + 1, end);

}

int binary_search_end(int* array, int target, int start, int end) {
	if (start > end) return 10000001;
	int mid = (start + end) / 2;

	if (array[mid] == target) {
		if (mid + 1 > end || array[mid + 1] != target) return mid;
		else return binary_search_end(array, target, mid + 1, end);
	}
	else if (array[mid] > target) return binary_search_end(array, target, start, mid - 1);
	else return binary_search_end(array, target, mid + 1, end);

}

int main(void) {
	int N, M;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr1[i]);
	}
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &arr2[i]);
	}
	qsort(arr1, N, sizeof(int), compare);

	for (int i = 0; i < M; i++) {
		int index = binary_search_start(arr1, arr2[i], 0, N - 1);
		if (index == 10000001) continue;
		else {
			arr3[i] = binary_search_end(arr1, arr2[i], 0, N - 1) - index + 1;
		}
	}

	for (int i = 0; i < M; i++) {
		printf("%d ", arr3[i]);
	}

	return 0;
}