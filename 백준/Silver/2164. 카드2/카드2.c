#include <stdio.h>
#define SIZE 5000000

int queue[SIZE];
int rear = 0, front = 0;

int is_empty() {
	return front == rear;
}

void input(int data) {
	queue[rear++] = data;
}

int pop() {
	int data = queue[front++];
	return data;
}

int main(void) {
	int N, ary, check;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		input(i + 1);
	}
	for (int i = 0;; i++) {
		check = pop();
		if (is_empty()) break;
		input(check = pop());
		if (is_empty()) break;
	}

	printf("%d", check);

	return 0;
}