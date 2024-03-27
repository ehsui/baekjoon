#include <stdio.h>

int main(void){


	int M, N, sum, ans;
	int num[100];

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}//입력받기

	ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (i != j && i != k && j != k) {
					sum = num[i] + num[j] + num[k];
					if (sum <= M && sum >= ans) ans = sum;
				}
			}
		}
	}

	printf("%d", ans);

	return 0;
}
