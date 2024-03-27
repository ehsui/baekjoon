#include <stdio.h>
#include <string.h>

int main(void)
{
	int ary[3] = { 0, }, temp;

	while (1) {

		for (int i = 0; i < 3; i++) {
			scanf("%d", &ary[i]);
		}//입력받기

		if (ary[0] == 0) break; //000종료

		for (int i = 0; i < 2; i++) {
			for (int j = 0; (j + i) < 2; j++) {
				if (ary[j] > ary[j + 1]) {
					temp = ary[j];
					ary[j] = ary[j + 1];
					ary[j + 1] = temp;
				}
			}
		}//정렬하기
		if ((ary[2] * ary[2]) == (ary[1] * ary[1] + ary[0] * ary[0]))
		{
			printf("right\n");
		}
		else printf("wrong\n");

	}


	return 0;
}
