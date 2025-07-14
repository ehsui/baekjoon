#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;


void BFS(queue<pair<int, int>> q);

vector<vector<int>> adj;
vector<vector<int>> date;
int M, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> M >> N;
	adj.assign(N, vector<int>(M)); // N행 M열의 adj 배열
	date.assign(N, vector<int>(M)); // N행 M열의 date 배열

	// 격자 그래프 입력
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			cin >> adj[row][col];
			date[row][col] = -1;
		}
	}

	queue <pair<int, int>> q;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {

			// 처음부터 익어있는 토마토 모두 queue에 삽입
			if (adj[row][col] == 1) {
				q.push({ col, row });
				date[row][col] = 0;
			}
		}
	}

	BFS(q);

	int maxDate = 0;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			if (adj[row][col] != -1) {
				if (date[row][col] == -1) {
					cout << -1;
					return 0;
				}
				else maxDate = maxDate < date[row][col] ? date[row][col] : maxDate;
			}
		}
	}

	cout << maxDate;

	return 0;
}

// date 계산
void BFS(queue<pair<int, int>> q) {
	int dy[] = { -1, 1, 0, 0 }; int dx[] = { 0, 0, -1, 1 };
	int currentX, currentY, nextX, nextY;


	while (!q.empty()) {

		currentX = q.front().first;
		currentY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = currentX + dx[i], nextY = currentY + dy[i];

			if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N && adj[nextY][nextX] != -1) {

				// 방문한 적 없거나, 방문한 적 있지만 이 경로가 더 최단 경로일 때 date 업데이트
				if (date[nextY][nextX] == -1 || date[nextY][nextX] > date[currentY][currentX] + 1) {
					date[nextY][nextX] = date[currentY][currentX] + 1;
					q.push({ nextX, nextY });
				}
			}
		}
	}

}