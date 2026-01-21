#include <iostream>
#include <string.h>

using namespace std;

int DP(int a, int b, int c);
int dp[21][21][21];

int main()
{

    int a, b, c, result;

    memset(dp, -1, sizeof(dp));

    dp[0][0][0] = 1;

    while (1)
    {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            return 0;

        result = DP(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << result << "\n";
    }

    return 0;
}

int DP(int a, int b, int c)
{

    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return DP(20, 20, 20);

    if (dp[a][b][c] != -1)
        return dp[a][b][c];
    else
    {
        if (a < b && b < c)
        {
            dp[a][b][c] = DP(a, b, c - 1) + DP(a, b - 1, c - 1) - DP(a, b - 1, c);
            return dp[a][b][c];
        }
        else
        {
            dp[a][b][c] = DP(a - 1, b, c) + DP(a - 1, b - 1, c) + DP(a - 1, b, c - 1) - DP(a - 1, b - 1, c - 1);
            return dp[a][b][c];
        }
    }
}