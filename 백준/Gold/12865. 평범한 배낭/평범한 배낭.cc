#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> bag(N);
    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> bag[i].first >> bag[i].second;
    }

    sort(bag.begin(), bag.end());

    for (int i = 0; i < N; i++)
    {
        for (int j = K; j >= bag[i].first; j--)
        {
            dp[j] = max(dp[j], dp[j - bag[i].first] + bag[i].second);
        }
    }

    cout << dp[K];

    return 0;
}