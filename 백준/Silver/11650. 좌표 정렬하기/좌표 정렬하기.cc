#include <stdio.h>
#include <stdlib.h>
#define SIZE 100001

struct Data {
	int x;
	int y;
} a[SIZE];

typedef struct Data D;

int compare(const void* a, const void* b) {
	D *ptr1 = (D*)a;
	D *ptr2 = (D*)b;

	if (ptr1->x == ptr2->x) {
		return ptr1->y - ptr2->y;
	}
	else return ptr1->x - ptr2->x;
}


int main(void) {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}// 데이터 입력받기

	qsort((int*) a, N, sizeof(int)*2, compare);


	for (int i = 0; i < N; i++) {
		printf("%d %d\n", a[i].x, a[i].y);
	}// 데이터 출력하기

	return 0;
}



