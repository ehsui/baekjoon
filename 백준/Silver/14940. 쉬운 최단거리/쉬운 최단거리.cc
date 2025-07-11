#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 목표 지점
vector<vector<int>> board;
vector<vector<int>> visited;
vector<vector<int>> dist;

int n, m;
pair<int, int> goal;

void BFS(int x, int y);

int main() {

	// 입력 속도
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 예제 입력
	cin >> n >> m;

	// board, visited, dist 벡터 크기 초기화
	board.resize(n, vector<int>(m));
	visited.resize(n, vector<int>(m, 0));
	dist.resize(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];

			if (board[i][j] == 2) goal = { j,i };
			if (board[i][j] == 0) dist[i][j] = 0;
		}
	}


	BFS(goal.first, goal.second);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] <<" ";
		}
		cout << "\n";
	}
	return 0;
}

void BFS(int x, int y) {

	int current_x, current_y;
	queue<pair<int, int>> q;

	// 상하좌우 이동 배열
	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };
	int next_x, next_y;

	// 시작 지점 (목표 지점을 시작으로 모든 경로 탐색)
	q.push({ x, y });
	dist[y][x] = 0;
	visited[y][x] = 1;

	while (!q.empty()) {

		current_x = q.front().first;
		current_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			next_x = current_x + dx[i]; next_y = current_y + dy[i];

			if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n 
				&& visited[next_y][next_x] == 0 && board[next_y][next_x] != 0) {

				q.push({ next_x, next_y });
				visited[next_y][next_x] = 1;
				dist[next_y][next_x] = dist[current_y][current_x] + 1;
			}
		}
	}

	return;
}