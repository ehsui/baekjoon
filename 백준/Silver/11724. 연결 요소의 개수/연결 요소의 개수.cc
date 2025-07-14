#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

bool DFS(int n);

vector<vector<int>> graph;
vector<int> visited;

int main() {
	int N, M, first, second, answer = 0;

	cin >> N >> M;

	graph.resize(N + 1);
	visited.resize(N + 1, -1);

	// 1번에 1이 들어 있음
	for (int i = 0; i < M; i++) {
		cin >> first >> second;

		// 간선 추가
		graph[first].push_back(second);
		graph[second].push_back(first);
	}

	for (int i = 1; i <= N; i++) {

		if (DFS(i)) answer++;
	}

	cout << answer;

	return 0;
}

bool DFS(int n) {
	stack<int> st;
	int current_node, next_node;

	// 기저 상황
	// n이 이미 방문한 노드라면 이미 연결 요소에 포함되어있고, 그 개수를 포함했으므로 false;
	if (visited[n] != -1) return false;

	// 방문하지 않았으면 true;
	st.push(n);

	while (!st.empty()) {

		current_node = st.top();
		st.pop();
		visited[current_node] = 1;

		for (int i = 0; i < graph[current_node].size(); i++) {

			next_node = graph[current_node][i];

			if (visited[next_node] == -1) {
				st.push(next_node);
				visited[next_node] = 1;
			}
		}
	}

	return true;
}