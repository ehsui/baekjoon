#include <iostream>
#include <vector>

using namespace std;
using Edge = pair<int, int>;

vector<vector<Edge>> graph;

void dfs(int node, int target, int weight, int parent);
int ans;

int main()
{

    int N, M, n1, n2, w;

    cin >> N >> M;

    graph.resize(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        cin >> n1 >> n2 >> w;

        graph[n1].push_back({n2, w});
        graph[n2].push_back({n1, w});
    }

    for (int i = 0; i < M; i++)
    {
        cin >> n1 >> n2;
        dfs(n1, n2, 0, -1);
        cout << ans << "\n";
    }

    return 0;
}

void dfs(int node, int target, int weight, int parent)
{

    if (node == target)
    {
        ans = weight;
        return;
    }

    for (int i = 0; i < graph[node].size(); i++)
    {
        if (graph[node][i].first == parent)
            continue;
        dfs(graph[node][i].first, target, weight + graph[node][i].second, node);
    }
}