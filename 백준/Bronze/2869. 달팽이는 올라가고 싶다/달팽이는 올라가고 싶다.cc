#include <stdio.h>

int main(void) {
	int B, A, V, index = 0, answer = 1;

	scanf("%d %d %d", &A, &B, &V);


	if (index + A > V) {
		printf("%d", answer);
	}//answer=1인 경우
	else {
		if ((V - A) % (A - B) == 0) {
			answer = (V - A) / (A - B) + 1;
		}
		else {
			answer = (V - A) / (A - B) + 2;
		}
		printf("%d", answer);
	}

	return 0;
}