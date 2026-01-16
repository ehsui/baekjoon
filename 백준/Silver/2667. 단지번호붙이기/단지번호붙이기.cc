#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int DFS(int y, int x);

int N, tmp;
int **map;
bool **visited;

int main()
{
    vector<int> answer;

    cin >> N;

    map = new int *[N];
    visited = new bool *[N];

    for (int i = 0; i < N; i++)
    {
        map[i] = new int[N];
        visited[i] = new bool[N];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                answer.push_back(DFS(i, j));
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << endl;

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}

int DFS(int y, int x)
{
    visited[y][x] = true;
    int count = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            continue;

        if (map[ny][nx] == 1 && !visited[ny][nx])
        {
            count += DFS(ny, nx);
        }
    }

    return count;
}