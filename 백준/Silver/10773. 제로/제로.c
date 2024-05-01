#include <stdio.h>
#define MAX_SIZE 100000

int stack[MAX_SIZE];
int top = -1;

void input(int data) {
	stack[++top] = data;
}

void pop() {
	--top;
}

int sum() {
	int answer = 0;
	for (int i = 0; i < top + 1; i++) {
		answer += stack[i];
	}

	return answer;
}

int main(void) {
	int K, answer;
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%d", &answer);
		
		if (answer == 0) {
			pop();
		}
		else {
			input(answer);
		}
	}

	answer = sum();

	printf("%d", answer);

	return 0;
}