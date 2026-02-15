#include <iostream>

using namespace std;

int main()
{

    int T, n, dp[11];

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n;
        for (int i = 4; i <= n; i++)
        {
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        }

        cout << dp[n] << "\n";
    }
}