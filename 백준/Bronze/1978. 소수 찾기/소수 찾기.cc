#include <stdio.h>

int main(void){

	int N, ary[100] = { 0, }, num = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int check = 0;
		scanf("%d", &ary[i]);

		if (ary[i] != 1) {
			for (int j = 2; j < ary[i]; j++) {
				if ((ary[i] % j) == 0) {
					check = 1;
					break;
				}
			}
			if (check == 0) num += 1;
		}

	}

	printf("%d", num);

	return 0;
}
