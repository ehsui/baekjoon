#include <stdio.h>

int Bottom_Up(int n) {
	int x = n / 3;
	int tmp = -1;
	for (int i = 0; i <= x; i++) {//5
		for (int j = 0; i + j <= x; j++) {//3
			if ((n - 3 * j - 5 * i) == 0) {
				tmp = i + j;
			}
		}
	}

	return tmp;
}

int main(void) {
	int N;

	scanf("%d", &N);
	
	int answer = Bottom_Up(N);
	printf("%d", answer);
	
	return 0;
}