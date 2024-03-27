#include <stdio.h>

int main(void) {


	
	for (int j = 0;; j++) {
		int ary[5], check = 0, num, count = 0;
		scanf("%d", &num);
		if (num == 0) return 0;

		while (num != 0)
		{
			ary[count] = num % 10;
			num = num / 10;
			++count;
		}

		if (count % 2 == 0) {
			for (int i = 0; i < count; i++) {
				if (ary[i] != ary[count - 1 - i]) {
					check = 1;
				}
			}
		}//짝수
		else {
			for (int i = 0; i < count; i++) {
				if (i == (count / 2)) {
					continue;
				}
				if (ary[i] != ary[count - 1 - i]) {
					check = 1;
				}
			}
		}//홀수

		if (check == 1) printf("no\n");
		else printf("yes\n");
	}
	return 0;
}
