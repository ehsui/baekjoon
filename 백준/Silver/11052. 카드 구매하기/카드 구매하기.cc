#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int N;
    cin >> N;

    vector<int> cards(N + 1);
    vector<int> dp(N + 1);

    // i가 카드 개수, cards[i] 값이 카드 가격
    for (int i = 1; i <= N; i++)
    {
        cin >> cards[i];
        dp[i] = cards[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i] = max(dp[i], dp[i - j] + cards[j]);
        }
    }

    cout << dp[N];
    return 0;
}