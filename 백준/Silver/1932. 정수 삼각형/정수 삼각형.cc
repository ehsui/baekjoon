#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n;

    cin >> n;

    vector<vector<int>> vec(n + 1, vector<int>(n + 1));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> vec[i][j];
        }
    }

    dp[0][0] = vec[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][0] + vec[i][j];
            }
            else if (j == i)
            {
                dp[i][j] = dp[i - 1][j - 1] + vec[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + vec[i][j];
            }
        }
    }

    int max = *max_element(dp[n - 1].begin(), dp[n - 1].end());
    cout << max;

    return 0;
}