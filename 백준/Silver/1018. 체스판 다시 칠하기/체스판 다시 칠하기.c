#include <stdio.h>

int main(void) {
	char board[50][50] = { 0 };
	int x, y, answer = 0;
	int index_x = 0, index_y = 0;
	
	scanf("%d %d", &y, &x);
	for (int j = 0; j < y; j++) {
		for (int i = 0; i < x; i++) {
			scanf(" %c", &board[j][i]);
		}
	}

	for (int p = 0; p <= y - 8; p++) { // x 시작점 돌기
		for (int q = 0; q <= x - 8; q++) { // y 시작점 돌기
			int answerA = 0, answerB = 0;

			for (int j = p; j < 8 + p; j++) {
				for (int i = q; i < 8 + q; i++) {
					if ((j % 2 == 0 && i % 2 == 1) || (j % 2 == 1 && i % 2 == 0)) {
						if (board[j][i] == 'W') answerA++;
						if (board[j][i] == 'B') answerB++;
					}//홀수행
					else {
						if (board[j][i] == 'W') answerB++;
						if (board[j][i] == 'B') answerA++;
					}//짝수행
				}
			}

			if (answerA >= answerB && answerA>=answer) {
				answer = answerA;
			}
			else if (answerB >= answerA && answerB >= answer) {
				answer = answerB;
			}
		}
	}
	 
	printf("%d", 64 - answer);

	return 0;
}