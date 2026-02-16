#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(int v);
void DFS(int v);

int N, M, V;
vector<vector<int>> graph;
vector<bool> isvisited;

int main()
{
    cin >> N >> M >> V;

    graph.resize(N + 1, vector<int>());
    isvisited.resize(N + 1, false);

    int x, y;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(V);
    cout << "\n";

    for (int i = 1; i <= N; i++)
    {
        isvisited[i] = false;
    }
    BFS(V);

    return 0;
}

void DFS(int v)
{
    isvisited[v] = true;
    cout << v << " ";
    for (int i = 0; i < graph[v].size(); i++)
    {
        int next = graph[v][i];

        if (!isvisited[next])
        {
            DFS(next);
        }
    }
}

void BFS(int v)
{
    queue<int> q;

    q.push(v);
    isvisited[v] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!isvisited[next])
            {
                isvisited[next] = true;
                q.push(next);
            }
        }
    }
}
