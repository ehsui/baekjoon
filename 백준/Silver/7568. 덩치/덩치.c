#include <stdio.h>

struct kgcm {
	int kg;
	int cm;
	int rank;
};

int main(void) {
	struct kgcm ary[50];
	struct kgcm tmp;
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &ary[i].kg, &ary[i].cm);
		ary[i].rank = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (ary[i].kg < ary[j].kg && ary[i].cm < ary[j].cm) ary[i].rank++;
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", ary[i].rank);
	}

	return 0;
}