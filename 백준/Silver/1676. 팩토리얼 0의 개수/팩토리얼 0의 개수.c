#include <stdio.h>

int main(void) {

	int N, two = 0, five = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int tmp = i;
		for (;;) {
			if ((tmp % 2) == 0) {
				two++;
				tmp /= 2;
			}
			else if ((tmp % 5) == 0) {
				five++;
				tmp /= 5;
			}
			else break;
		}
	}
	int answer;

	answer = two <= five ? two : five;

	printf("%d", answer);

	return 0;
}