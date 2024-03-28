#include <stdio.h>

int main(void)
{
	int T, H, W, N, X, Y;
	scanf("%d", &T);
	while (T > 0) {
		scanf("%d %d %d", &H, &W, &N);

		if (N % H == 0) {
			X = N / H;
			Y = H;
		}
		else {
			X = (N / H) + 1;
			Y = N % H;
		}
		if (X < 10) printf("%d%d%d\n", Y,0,X);
		else printf("%d%d\n", Y, X);
		T -= 1;
	}
	return 0;
}
