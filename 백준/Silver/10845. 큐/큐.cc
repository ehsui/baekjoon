#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10001

int queue[MAX_SIZE];
int front_ = 0, rear = 0;

int is_empty() {
	return front_ == rear;
}// 큐가 비어있는지 확인하는 함수

void push(int data) {
	queue[rear++] = data;
} //정수 x를 큐에 넣는 연산

int pop() {
	if (is_empty()) return -1;
	int data = queue[front_++];
	return data;
}

int size() {
	return rear-front_;
}// 큐에 들어있는 정수의 개수를 출력

int empty() {
	if (is_empty()) return 1;
	else return 0;
}

int front() {
	if (is_empty()) return -1;
	return queue[front_];
}// 큐의 가장 앞에 있는 정수 출력

int back() {
	if (is_empty()) return -1;
	return queue[rear-1];
}// 큐의 가장 뒤에 있는 정수 출력

int main(void) {
	int N, number;
	char answer[6] = { 0 };
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", answer);
		if (strncmp(answer, "push", 4) == 0) {
			scanf("%d", &number);
			push(number);
		}
		else if (strncmp(answer, "pop", 3) == 0) {
			printf("%d\n",pop());
		}
		else if (strncmp(answer, "size", 4) == 0) {
			printf("%d\n", size());
		}
		else if (strncmp(answer, "empty", 5) == 0) {
			printf("%d\n", empty());
		}
		else if (strncmp(answer, "front", 5) == 0) {
			printf("%d\n", front());
		}
		else if (strncmp(answer, "back", 4) == 0) {
			printf("%d\n", back());
		}
	}

	return 0;
}