#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int N, vector<vector<int>>& w, vector<bool>& visited) {
	visited[N] = true;
	
	for (int i = 0; i < w[N].size(); i++) {
		int next = w[N][i];
		if (!visited[next]) {
			DFS(next, w, visited);
		}
	}
}

int main(){
	int n, repeat, n1, n2;

	cin >> n;
	cin >> repeat;

	vector<bool> visited(n+1, false);
	vector<vector<int>> w(n+1);

	for (int i = 0; i < repeat; i++) {
		cin >> n1 >> n2;
		w[n1].push_back(n2);
		w[n2].push_back(n1);
	}

	DFS(1, w, visited);

	int result = count(visited.begin(), visited.end(), true) - 1;
	cout << result;

	return 0;
}