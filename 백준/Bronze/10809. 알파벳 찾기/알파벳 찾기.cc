#include <stdio.h>

int main(void)
{
	char ch, word[101] = {0, };
	int num[26];

	for (int k = 0; k <= 25; k++) {
		num[k] = -1;
	} //모든 값 -1로 초기화

	for (int j = 0; j <= 101; j++) {
		word[j]=getchar();
		if (word[j] == '\n') break;
		for (ch = 97; ch <= 122; ch++) {
			if (word[j] == ch) {
				if (num[ch - 97] == -1) num[ch - 97] = j;
			}
		}
	}

	for (int k = 0; k <= 24; k++) {
		printf("%d ", num[k]);
	}
	printf("%d",num[25]);

	return 0;
}
