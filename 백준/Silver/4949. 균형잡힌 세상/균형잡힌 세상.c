#include <stdio.h>
#define SIZE 50

char stack[SIZE];
int index = -1;

void init() {
	index = -1;
}

int is_empty() {
	if (index == -1) return 1;
	else return 0;
}

char pop() {
	if (is_empty()) return 0;
	char answer = stack[index--];
	return answer;
}

void put(char value) {
	stack[++index] = value;
}

int check(char value) {

	if (value == '(' || value == '[') {
		put(value); return 1;
	}
	else if (value == ')'){
		char tmp = pop();
		if (tmp == '(') return 1;
		else return 0;
	}
	else if (value == ']') {
		char tmp = pop();
		if (tmp == '[') return 1;
		else return 0;
	}

}

int main(void) {
	int check_no = 0;
	char first;
	int i;

	for (;;) {
		check_no = 0;
		init();

		for (i = 0;; i++) {
			char test;

			//scanf(" 1c", &test);
			test = getchar();

			if (test == '.') break;
			if (check(test) == 0) {
				check_no = 1;
			}
			else continue;
		}

		if (i == 1) return 0;
		if (check_no == 1 || index != -1) printf("no\n");
		else printf("yes\n");

	}



	return 0;
}