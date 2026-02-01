#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

void bfs(int y, int x);
int N, M;

int adj[101][101];
bool visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{

    cin >> N >> M;

    memset(visited, 0, sizeof(visited));

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < M + 1; j++)
        {
            scanf("%1d", &adj[i][j]);
        }
    }

    bfs(1, 1);

    cout << adj[N][M];

    return 0;
}

void bfs(int startY, int startX)
{
    queue<pair<int, int>> q;
    q.push({startY, startX});

    int cx, cy, nx, ny;
    visited[startY][startX] = 1;

    while (!q.empty())
    {
        cy = q.front().first;
        cx = q.front().second;

        q.pop();
        if (cx == N && cy == M)
        {
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (nx >= 1 && ny >= 1 && nx <= M && ny <= N)
            {
                if (adj[ny][nx] == 1 && !visited[ny][nx])
                {
                    visited[ny][nx] = true;

                    adj[ny][nx] = adj[cy][cx] + 1;

                    q.push({ny, nx});
                }
            }
        }
    }
}