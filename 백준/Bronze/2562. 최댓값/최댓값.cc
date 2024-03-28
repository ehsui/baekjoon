#include <stdio.h>


int main(void) {
	int n;
	int bn = 0, line = 0;
	for (int i = 1; i < 10; i++) {
		scanf("%d", &n);
		if (n > bn) { bn = n; line = i; }
	}

	printf("%d\n%d", bn, line);
	return 0;
}