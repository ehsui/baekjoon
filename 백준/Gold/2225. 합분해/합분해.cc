#include <iostream>

using namespace std;

int main()
{
    int N, K;

    cin >> N >> K;

    long long DP[201][201];

    for (int i = 0; i <= N; i++)
    {
        DP[1][i] = 1;
    }

    for (int i = 0; i <= K; i++)
    {
        DP[i][0] = 1;
    }

    for (int i = 2; i <= K; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % 1000000000;
        }
    }

    cout << DP[K][N] << "\n";

    return 0;
}