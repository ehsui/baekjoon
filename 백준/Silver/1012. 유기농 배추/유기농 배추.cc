#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, M, N, K;

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int cnt = 0;

		cin >> M >> N >> K;

		bool board[50][50] = {0};
		bool visited[50][50] = {0};

		queue<pair<int, int>> point_q;

		// 상 하 좌 우
		int dy[] = { -1, 1, 0, 0 }; // Y (행) 좌표 변화
		int dx[] = { 0, 0, -1, 1 }; // X (열) 좌표 변화

		int X, Y;
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;

			board[Y][X] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				// 배추가 있고 방문 x
				if (board[i][j] == 1 && visited[i][j] != 1) {

					cnt++;

					point_q.push({ j, i });
					visited[i][j] = 1;

					while (!point_q.empty()) {
						pair<int, int> current_point = point_q.front(); 
						point_q.pop();

						int current_x = current_point.first;
						int current_y = current_point.second;

						// 4가지 방향 (상, 하, 좌, 우) 탐색
						for (int k = 0; k < 4; ++k) {
							int next_x = current_x + dx[k];
							int next_y = current_y + dy[k];

							// 다음 좌표가 범위 내에 있는지 확인
							if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N) {

								// 다음 좌표에 배추가 있고 아직 방문 x
								if (board[next_y][next_x] == 1 && visited[next_y][next_x] == 0) {
									visited[next_y][next_x] = 1;
									point_q.push({ next_x, next_y });
								}
							}
						}
					}
				}
			}
		}

		cout << cnt << "\n";
	}

}