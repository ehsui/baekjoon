#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N, K;

	scanf("%d %d", &N, &K);

	int ary[1001] = { 0 };
	int ary2[1001] = { 0 };

	for (int i = 0; i < N; i++) {
		ary[i] = i + 1;
	}

	int check = 1;
	int j = 0;

	for (int i = 0;; i++) {
		if (i == N) i = 0;
		if (ary[i] == 0) continue;
		else {
			if (check == K) {
				check = 1;
				ary2[j] = i + 1;
				j++;
				ary[i] = 0;
				if (j == N) break;
			}
			else {
				check++;
			}
		}
	}
	printf("<");
	for (int i = 0; i < N; i++) {
		if (i == N - 1) printf("%d", ary2[i]);
		else printf("%d, ", ary2[i]);
	}
	printf(">");

	return 0;
}