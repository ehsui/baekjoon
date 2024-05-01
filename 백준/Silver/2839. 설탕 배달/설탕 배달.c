#include <stdio.h>

int Bottom_Up(int n) {
	int x = n / 3;
	int y = n / 5;
	int tmp = -1;
	for (int i = 0; i <= x; i++) {//3
		for (int j = 0; j <= y; j++) {//5
			if ((n - 5 * j - 3 * i) == 0) {
				return i + j;
			}
		}
	}

	return -1;
}

int main(void) {
	int N;

	scanf("%d", &N);
	
	int answer = Bottom_Up(N);
	printf("%d", answer);
	
	return 0;
}
