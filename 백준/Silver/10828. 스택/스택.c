#include <stdio.h>
#include <string.h>
#define SIZE 100000

int stack[SIZE];
int top_ = -1;

int IsEmpty() {
	if (top_ < 0) return 1;
	else return 0;
}

void push(int value) {
	stack[++top_] = value;
}

int pop() {
	if (IsEmpty() == 1) return -1;
	return stack[top_--];
}

int top() {
	if (IsEmpty() == 1) return -1;
	return stack[top_];
}

int size() {
	return top_ + 1;
}

int main(void) {
	int N, num;
	char ary[5];
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", ary);
		if (strncmp(ary, "push", 4)==0) {
			scanf("%d", &num);
			push(num);
		}
		else if (strncmp(ary, "top", 3)==0) {
			printf("%d\n", top());
		}
		else if (strncmp(ary, "size", 4)==0) {
			printf("%d\n", size());
		}
		else if (strncmp(ary, "empty", 5)==0) {
			printf("%d\n", IsEmpty());
		}
		else if (strncmp(ary, "pop", 3)==0) {
			printf("%d\n", pop());
		}
	}

	return 0;
}