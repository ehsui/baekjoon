#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Edge = pair<int, int>;

void dfs(int weight, int a, int parent);

vector<vector<Edge>> graph;
vector<int> weights;
int ans = 0, final_node;

int main()
{
    int n;
    cin >> n;

    graph.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    dfs(0, 1, -1);

    ans = 0;
    dfs(0, final_node, -1);

    cout << ans << "\n";
    return 0;
}

void dfs(int weight, int a, int parent)
{
    if (ans < weight)
    {
        ans = weight;
        final_node = a;
    }

    for (int i = 0; i < graph[a].size(); i++)
    {
        if (graph[a][i].first == parent)
            continue;
        dfs(weight + graph[a][i].second, graph[a][i].first, a);
    }
}