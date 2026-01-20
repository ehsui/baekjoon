#include <iostream>

using namespace std;

int main()
{

    int N;

    cin >> N;

    int (*dp)[10] = new int[N + 1][10];

    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
        dp[2][i] = i + 1;
    }

    for (int i = 3; i < N + 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            dp[i][j] = 0;

            for (int k = 0; k <= j; k++)
            {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 10; i++)
    {
        result += dp[N][i];
        result %= 10007;
    }

    cout << result;

    return 0;
}