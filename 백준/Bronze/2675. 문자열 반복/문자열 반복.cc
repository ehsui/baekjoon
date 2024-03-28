#include <stdio.h>

int main(void)
{
	int R, T;
	char S[21];

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %s", &R, S);
		for (int j = 0; S[j] != '\0'; j++) {
			for (int x = 0; x < R; x++) {
				printf("%c", S[j]);
			}
			
		}
		printf("\n");
	}

	return 0;
}
