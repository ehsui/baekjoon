#include <stdio.h>
#include <stdlib.h>
#define SIZE 100001

struct Data {
	int age;
	char name[101];
	int number;
} a[SIZE];

typedef struct Data D;

int compare(const void* a, const void* b) {
	D* ptr1 = (D*)a;
	D* ptr2 = (D*)b;

	if (ptr1->age == ptr2->age) {
		return ptr1->number - ptr2->number;
	}
	else return ptr1->age - ptr2->age;
}

int main(void) {
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %s", &a[i].age, a[i].name);
		a[i].number = i;
	}

	qsort(a, N, sizeof(D), compare);

	for (int i = 0; i < N; i++) {
		printf("%d %s\n", a[i].age, a[i].name);
	}
	return 0;
}