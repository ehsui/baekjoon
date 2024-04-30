#include <stdio.h>
#define SIZE 50

char stack[SIZE];
int index = -1;

int is_empty() {
	if (index == -1) return 1;
	else return 0;
}

char pop() {
	char answer = stack[index];
	index -= 1;
	return answer;
}

void put(char value) {
	index += 1;
	stack[index] = value;
}

int check(char value[]) {

	for (int i = 0; value[i] != '\0'; i++) {
		if (value[i] == '(') {
			put('(');

		}
		else {
			char tmp = pop();
			if (tmp == '(') continue;
			else return 0;
		}
	}

	if (index == -1) return 1;
	else return 0;
}

int main(void) {

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char test[50];
		scanf("%s", test);
		if (check(test) == 1) printf("YES\n");
		else printf("NO\n");
		index = -1;
	}
	return 0;
}