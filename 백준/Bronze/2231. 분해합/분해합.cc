#include <stdio.h>

int main(void) {
	int index, x, M, N, check = 0;
	int ary[7];

	scanf("%d", &N);

	for (int i = 1; i <N; i++) {
		
		x = i;

		for (int k = 0;; k++) {
			x /= 10;
			if (x < 1) {
				index = k+1;
				break;
			}
		}//자릿수 세기
		
		x = i;

		for (int j = 0; j < index; j++) {
			 ary[j] = x % 10;
			 x /= 10;
		}
		x = i;

		for (int k = 0; k < index; k++) {
			x += ary[k];
		}
		                                   
		if (x == N) {
			M = i;
			check = 1;
			break;
		}
	}

	if (check == 0) printf("0");
	else printf("%d", M);

	return 0;
}