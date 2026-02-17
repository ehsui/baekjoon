#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int N, T;

    cin >> N >> T;

    vector<pair<int, int>> test(N + 1);
    vector<int> dp(T + 1, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> test[i].first >> test[i].second;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = T; j >= test[i].first; j--)
        {
            dp[j] = max(dp[j], dp[j - test[i].first] + test[i].second);
        }
    }

    cout << dp[T];

    return 0;
}