#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct xyz
{
    int x;
    int y;
    int z;
};

void BFS();
xyz dxyz[6] = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 0, -1}, {-1, 0, 0}, {0, -1, 0}};
int M, N, H, tomato[100][100][100], day[100][100][100];
queue<xyz> q;

int main()
{

    cin >> M >> N >> H;

    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                cin >> tomato[h][n][m];
                if (tomato[h][n][m] == 1)
                    q.push({m, n, h});

                day[h][n][m] = 0;
            }
        }
    }

    BFS();

    int result = 0;
    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                if (tomato[h][n][m] == 0)
                { // 여전히 안 익은 게 있다면
                    cout << -1 << endl;
                    return 0;
                }
                result = max(result, day[h][n][m]);
            }
        }
    }

    cout << result;

    return 0;
}

void BFS()
{

    while (!q.empty())
    {
        xyz cur = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {

            xyz next = {cur.x + dxyz[i].x,
                        cur.y + dxyz[i].y,
                        cur.z + dxyz[i].z};

            if (next.x >= 0 && next.y >= 0 && next.z >= 0 && next.x < M && next.y < N && next.z < H)
            {

                if (tomato[next.z][next.y][next.x] == 0)
                {
                    tomato[next.z][next.y][next.x] = 1;
                    day[next.z][next.y][next.x] = day[cur.z][cur.y][cur.x] + 1;
                    q.push(next);
                }
            }
        }
    }
}
