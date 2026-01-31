#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

void dfs(int cur, int depth);

vector<vector<int>> human;
vector<bool> visited;
int result = -1;
int n, n1, n2, m, x, y;

int main()
{

    cin >> n >> n1 >> n2;
    cin >> m;

    human.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        human[x].push_back(y);
        human[y].push_back(x);
    }

    dfs(n1, 0);

    cout << result << endl;
    return 0;
}

void dfs(int cur, int depth)
{

    if (result != -1)
        return;

    if (cur == n2)
    {
        result = depth;
        return;
    }

    visited[cur] = true;

    for (int next : human[cur])
    {
        if (!visited[next])
            dfs(next, depth + 1);
    }
}
