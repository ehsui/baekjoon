#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point
{
    int x;
    int y;
};

int map[25][25], N;
bool visited[25][25];
int dfs(point start);

point dxy[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int main()
{
    vector<point> start;
    vector<int> answer;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%1d", &map[i][j]);
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == 0 && map[i][j] == 1)
            {
                answer.push_back(dfs({j, i}));
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << "\n";
    }

    return 0;
}

int dfs(point cur)
{
    visited[cur.y][cur.x] = true;
    int count = 1;

    for (int i = 0; i < 4; i++)
    {
        point next = {cur.x + dxy[i].x,
                      cur.y + dxy[i].y};

        if (next.x >= 0 && next.y >= 0 && next.x < N && next.y < N)
        {
            if (map[next.y][next.x] == 1 && !visited[next.y][next.x])
            {
                count += dfs({next.x, next.y});
            }
        }
    }
    return count;
}