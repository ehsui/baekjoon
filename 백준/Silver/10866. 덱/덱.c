#include <stdio.h>
#include <string.h>
#define SIZE 10001

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[SIZE];
} DequeType; 


void init_deque(DequeType* dq) {
	dq->front = 0;
	dq->rear = 0;
}

int is_empty(DequeType* dq) {
	if (dq->front == dq->rear) return 1;
	else return 0;
}

void push_front(DequeType* dq, element item) {
	dq->data[dq->front] = item;
	dq->front = (dq->front - 1 + SIZE) % SIZE;
}

void push_back(DequeType* dq, element item) {
	dq->rear = (dq->rear + 1) % SIZE;
	dq->data[dq->rear] = item;
}

int pop_front(DequeType* dq) {
	if (is_empty(dq) == 1) return -1;
	else {
		dq->front = (dq->front + 1) % SIZE;
		return dq->data[dq->front];
	}
}

int pop_back(DequeType* dq) {
	element item;
	if (is_empty(dq) == 1) return -1;
	else {
		item = dq->data[dq->rear];
		dq->rear = (dq->rear - 1 + SIZE) % SIZE;
		return item;
	}
}

int size(DequeType* dq) {
	return (dq->rear - dq->front + SIZE) % SIZE;
}

int front(DequeType* dq) {
	if (is_empty(dq) == 1) return -1;
	return dq->data[(dq->front + 1) % SIZE];
}

int back(DequeType* dq) {
	if (is_empty(dq) == 1) return -1;
	return dq->data[(dq->rear + SIZE) % SIZE];
}

int main(void) {
	DequeType dq;
	init_deque(&dq);
	int N, number;
	char answer[100] = { 0 };
	scanf("%d", &N);
	

	for (int i = 0; i < N; i++) {
		scanf("%s", answer);
		if (strncmp(answer, "push_front", 10) == 0) {
			scanf("%d", &number);
			push_front(&dq, number);
		}
		else if (strncmp(answer, "push_back", 9) == 0) {
			scanf("%d", &number);
			push_back(&dq, number);
		}
		else if (strncmp(answer, "pop_front", 9) == 0) {
			printf("%d\n", pop_front(&dq));
		}
		else if (strncmp(answer, "pop_back", 8) == 0) {
			printf("%d\n", pop_back(&dq));
		}
		else if (strncmp(answer, "size", 4) == 0) {
			printf("%d\n", size(&dq));
		}
		else if (strncmp(answer, "empty", 5) == 0) {
			printf("%d\n", is_empty(&dq));
		}
		else if (strncmp(answer, "front", 5) == 0) {
			printf("%d\n", front(&dq));
		}
		else if (strncmp(answer, "back", 4) == 0) {
			printf("%d\n", back(&dq));
		}
	}

	return 0;
}
