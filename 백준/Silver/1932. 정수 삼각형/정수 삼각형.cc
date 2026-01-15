#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;

    cin >> N;

    int **dp;
    int **arr;

    dp = new int *[N + 1];
    arr = new int *[N + 1];

    for (int i = 0; i < N + 1; i++)
    {
        dp[i] = new int[N + 1];
        arr[i] = new int[N + 1];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
            {
                dp[i][j] = arr[i][j] + dp[i - 1][j];
            } // 고려할 부모가 오른쪽 하나
            else if (j == i)
            {
                dp[i][j] = arr[i][j] + dp[i - 1][j - 1];
            } // 고려할 부모가 왼쪽 하나
            else
            {
                dp[i][j] = max(arr[i][j] + dp[i - 1][j], arr[i][j] + dp[i - 1][j - 1]);
            } // 둘 다 고려해야 함
        }
    }

    int result = dp[N][1];

    for (int i = 2; i <= N; i++)
    {
        result = max(result, dp[N][i]);
    }

    cout << result;
    return 0;
}