#include <stdio.h>

int main(void)
{
	int i;
	char S[1001];

	scanf("%s", S);
	scanf("%d", &i);
	printf("%c", S[i-1]);

	return 0;
}
