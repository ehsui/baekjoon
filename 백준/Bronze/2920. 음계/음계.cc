#include <stdio.h>

int main(void)
{
	int mu[8], check;
	
	for (int j = 0; j <= 7; j++) {
		scanf("%d", &mu[j]);
	}

	if (mu[0] == 8) {
		check = 1;
		for (int i = 7; i > -1; i--) {
			if (mu[7-i] != i+1) {
				check = 2;
			}
		}
	}//8
	else if (mu[0] == 1) {
		check = 0;
		for (int i = 0; i < 8; i++) {
			if (mu[i] != i+1) {
				check = 2;
			}
		}
	}//1
	else check = 2;


	if (check == 0) printf("ascending");
	else if (check == 1) printf("descending");
	else printf("mixed");

	return 0;
}
