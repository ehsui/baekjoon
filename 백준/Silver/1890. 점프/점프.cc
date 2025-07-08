#include <iostream>
#include <cstring>

using namespace std;


long jump(int y, int x);

int N;
long gameboard[100][100], memoization[100][100];

int main() {	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> gameboard[i][j];
	}

	// -1로 초기화
	memset(memoization, -1, sizeof(memoization));
	cout << jump(0, 0);

	return 0;
}


long jump(int y, int x) {

	if (y >= N || x >= N) return 0;
	if (y == N - 1 && x == N - 1) return 1;


	long& ret = memoization[y][x];
	if (ret != -1) return ret;

	int jumpSize = gameboard[y][x];
	if (jumpSize == 0) return 0;

	return ret = (jump(y + jumpSize,x) + jump(y, x + jumpSize));
}