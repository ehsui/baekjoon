#include <iostream>

using namespace std;

int main()
{

    int N;
    cin >> N;

    int cost[1000][3];
    int dp[1000][3];
    int answer = 0;

    for (int i = 1; i <= N; i++)
    {

        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    dp[1][0] = cost[1][0];
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];

    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    int tmp = min(dp[N][0], dp[N][1]);
    answer = min(tmp, dp[N][2]);

    cout << answer;
    return 0;
}