#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	int N, K, current_point, next_point;
	int move[3] = { -1, 1, 2 };
	queue<int> q;
	vector<int> sec(100001, -1);

	cin >> N >> K;

	// 시작 지점
	sec[N] = 0;
	q.push(N);

	while (!q.empty()) {

		current_point = q.front();

		q.pop();

		if (current_point == K) break;

		for (int i = 0; i < 3; i++) {
			if (i == 2) next_point = current_point * 2;
			else next_point = current_point + move[i];

			if (next_point <= 100000 && next_point >= 0 && sec[next_point] == -1) {
				q.push(next_point);
				sec[next_point] = sec[current_point] + 1;
			}
		}
	}

	cout << sec[K];

	return 0;
}