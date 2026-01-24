#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n, k, tmp;
    vector<int> coins;
    int dp[10001] = {
        0,
    };

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        coins.push_back(tmp);
    }

    sort(coins.begin(), coins.end());

    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int C = coins[i];
        for (int j = C; j <= k; j++)
        {
            dp[j] += dp[j - C];
        }
    }

    cout << dp[k];

    return 0;
}