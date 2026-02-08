#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int N, M, answer = -1, tmp;

    cin >> N >> M;

    vector<vector<int>> vec(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> vec[i][j];
        }
    }

    // 4*1
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x + 3 < M; x++)
        {
            tmp = vec[y][x] + vec[y][x + 1] + vec[y][x + 2] + vec[y][x + 3];
            if (tmp > answer)
                answer = tmp;
        }
    }

    // 1*4
    for (int y = 0; y + 3 < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            tmp = vec[y][x] + vec[y + 1][x] + vec[y + 2][x] + vec[y + 3][x];
            if (tmp > answer)
                answer = tmp;
        }
    }

    // 2*2
    for (int y = 0; y + 1 < N; y++)
    {
        for (int x = 0; x + 1 < M; x++)
        {
            tmp = vec[y][x] + vec[y][x + 1] + vec[y + 1][x] + vec[y + 1][x + 1];
            if (tmp > answer)
                answer = tmp;
        }
    }

    // 2*3
    for (int y = 0; y + 2 < N; y++)
    {
        for (int x = 0; x + 1 < M; x++)
        {
            // 주황
            tmp = vec[y][x] + vec[y + 1][x] + vec[y + 2][x] + vec[y + 2][x + 1];
            if (tmp > answer)
                answer = tmp;

            tmp = vec[y][x] + vec[y][x + 1] + vec[y + 1][x + 1] + vec[y + 2][x + 1];
            if (tmp > answer)
                answer = tmp;

            tmp = vec[y][x + 1] + vec[y + 1][x + 1] + vec[y + 2][x + 1] + vec[y + 2][x];
            if (tmp > answer)
                answer = tmp;

            tmp = vec[y][x] + vec[y][x + 1] + vec[y + 1][x] + vec[y + 2][x];
            if (tmp > answer)
                answer = tmp;

            // 연두
            tmp = vec[y][x] + vec[y + 1][x] + vec[y + 1][x + 1] + vec[y + 2][x + 1];
            if (tmp > answer)
                answer = tmp;

            tmp = vec[y][x + 1] + vec[y + 1][x] + vec[y + 1][x + 1] + vec[y + 2][x];
            if (tmp > answer)
                answer = tmp;

            // 분홍
            tmp = vec[y][x] + vec[y + 1][x] + vec[y + 2][x] + vec[y + 1][x + 1];
            if (tmp > answer)
                answer = tmp;

            tmp = vec[y + 1][x] + vec[y][x + 1] + vec[y + 1][x + 1] + vec[y + 2][x + 1];
            if (tmp > answer)
                answer = tmp;
        }
    }

    // 3*2
    for (int y = 0; y + 1 < N; y++)
    {
        for (int x = 0; x + 2 < M; x++)
        {
            // 주황
            tmp = vec[y][x] + vec[y + 1][x] + vec[y][x + 1] + vec[y][x + 2];
            if (tmp > answer)
                answer = tmp;

            tmp = vec[y][x] + vec[y][x + 1] + vec[y][x + 2] + vec[y + 1][x + 2];
            if (tmp > answer)
                answer = tmp;

            tmp = vec[y][x] + vec[y + 1][x] + vec[y + 1][x + 1] + vec[y + 1][x + 2];
            if (tmp > answer)
                answer = tmp;

            tmp = vec[y + 1][x] + vec[y + 1][x + 1] + vec[y + 1][x + 2] + vec[y][x + 2];
            if (tmp > answer)
                answer = tmp;

            // 연두
            tmp = vec[y + 1][x] + vec[y + 1][x + 1] + vec[y][x + 1] + vec[y][x + 2];
            if (tmp > answer)
                answer = tmp;

            tmp = vec[y][x] + vec[y][x + 1] + vec[y + 1][x + 1] + vec[y + 1][x + 2];
            if (tmp > answer)
                answer = tmp;

            // 분홍
            tmp = vec[y][x] + vec[y + 1][x + 1] + vec[y][x + 1] + vec[y][x + 2];
            if (tmp > answer)
                answer = tmp;

            tmp = vec[y][x + 1] + vec[y + 1][x] + vec[y + 1][x + 1] + vec[y + 1][x + 2];
            if (tmp > answer)
                answer = tmp;
        }
    }

    cout << answer;
    return 0;
}