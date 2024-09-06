#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1001;
bool visited[MAX];
bool visited2[MAX];
vector<int> adj[MAX];
queue <int> Q;

void DFS(int cur) {
    visited[cur] = true;
    cout << cur << " ";

    for (int i = 0; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if (visited[next]) continue;
        DFS(next);
    }
}

void BFS(int cur) {
    visited2[cur] = true;
    Q.push(cur);

    while (!Q.empty()) {

        int next = Q.front();
        Q.pop();
        cout << next << " ";

        for (int i = 0; i < adj[next].size(); i++) {
            int x = adj[next][i];
            if (!visited2[x]) {
                Q.push(x);
                visited2[x] = true;
            }
        }
    }
}

int main() {
    int N, M, V;

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int input1, input2;
        cin >> input1 >> input2;
        adj[input1].push_back(input2);
        adj[input2].push_back(input1);
    }
    
    for (int j = 0; j < N; j++) {
        sort(adj[j + 1].begin(), adj[j + 1].end());
    }

    DFS(V);
    cout << "\n";
    BFS(V);

    return 0;
}