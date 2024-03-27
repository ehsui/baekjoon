#include <stdio.h>

int main(void){

	int N, an, bn, i, index;
	scanf("%d", &N);
	an = 2;
	bn = 7;
	if (N == 1) {
		printf("1");
		return 0;
	}

	for (i = 1; bn < 1000000000; i++) {
		an = 2 + 3 * i * (i - 1);
		bn = 1 + 3 * i * (i + 1);
		if (N >= an && N <= bn) {
			index = i;
			break;
		}
	}
	printf("%d", i+1);

		//겉의 개수가 개수로 늘어남
		//an1=2+3(n-1)n=3n^2-3n+2
		//an2=1+3n(n+1)
	return 0;

}
