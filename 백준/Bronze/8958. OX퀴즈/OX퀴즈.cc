#include <stdio.h>

int main(void)
{
	char ox;
	int i = 0, x, point = 0, bonus = 0;

	scanf("%d", &x);
	getchar();

	while (i < x) {
		while (1) {
			scanf("%c", &ox);
			if (ox == 'O') {
 				point += (1 + bonus);
				bonus += 1;
			}
			else if (ox == 'X') {
				bonus = 0;
			}
			else break; // 실행 종료
		}
		printf("%d\n", point);
		point = 0;
		bonus = 0;
		i += 1;
	}


	return 0;
}
