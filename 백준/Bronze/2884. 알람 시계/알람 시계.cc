#include <stdio.h>

int main(void)
{
	int H, M;
	scanf("%d %d", &H, &M);
	if (H == 0) {
		if (M - 45 > 0) printf("0 %d",M - 45); //H변화가 없을 떄
		else if (M - 45 < 0) printf("23 %d", 60 + (M - 45));
		else printf("0 0");
	}//전날 23시
	else {
		if (M - 45 > 0) printf("%d %d", H, M - 45); //H변화가 없을 떄
		else if (M - 45 < 0) printf("%d %d", H - 1, 60 + (M - 45));
		else printf("%d 0", H);
	}
	return 0;
}
