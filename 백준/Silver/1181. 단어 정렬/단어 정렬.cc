#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20001

struct Data {
	char name[51];
	int number;
} a[SIZE];

typedef struct Data D;

int compare(const void* a, const void* b) {
	D* ptr1 = (D*)a;
	D* ptr2 = (D*)b;
	if (ptr1->number == ptr2->number) {
		return strcmp(ptr1->name, ptr2->name);
	}
	else {
		return (ptr1->number - ptr2->number);
	}
}

int main(void) {
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s",a[i].name);
		a[i].number = strlen(a[i].name);
	}

	qsort(a, N, sizeof(D), compare);

	for (int i = 0; i < N; i++) {
		int check = 0;
		for (int j = 0; j < i; j++) {
			if (strcmp(a[i].name, a[j].name) == 0) {
				check = 1;
				break;
			}
		}
		if (check == 1) continue;
		printf("%s\n", a[i].name);
	}
	return 0;
}