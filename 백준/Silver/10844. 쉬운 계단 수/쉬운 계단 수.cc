#include <iostream>

using namespace std;

int main()
{

    int N;
    cin >> N;

    long long (*DP)[10] = new long long[N + 1][10];

    for (int i = 1; i < 10; i++)
    {
        DP[1][i] = 1;
    }

    for (int i = 2; i < N + 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 9)
            {
                DP[i][j] = (DP[i - 1][j - 1]) % 1000000000;
            }
            else if (j == 0)
            {
                DP[i][j] = (DP[i - 1][j + 1]) % 1000000000;
            }
            else
            {
                DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < 10; i++)
    {
        answer += DP[N][i];
        answer %= 1000000000;
    }

    cout << answer;

    return 0;
}