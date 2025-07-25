#include <iostream>
#include <vector>

using namespace std;

void paper(int size, int r, int c);
int paperArr[128][128];
int answer[2] = { 0, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paperArr[i][j];
		}
	}

	paper(N, 0, 0);

	cout << answer[0] << "\n" << answer[1];

	return 0;
}

void paper(int size, int r, int c) {
	// 4 분면으로 나누어서 
	// 각 사분면에 1과 0이 혼합된 자료가 있는 지 봐야 함.

	int half = size / 2;

	int color = paperArr[r][c];
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {

			if (color != paperArr[i][j]) {
				paper(half, r, c);
				paper(half, r + half, c);
				paper(half, r, c + half);
				paper(half, r + half, c + half);
				return;
			}
		}
	}

	if (color == 0) {
		answer[0] += 1;
	}
	else {
		answer[1] += 1;
	}

	return;
}