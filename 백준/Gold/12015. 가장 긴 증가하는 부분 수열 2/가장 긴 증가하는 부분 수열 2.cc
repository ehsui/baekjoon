#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, input;
    cin >> N;

    vector<int> arr = vector<int>(N + 1);
    vector<int> dp;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (dp.empty() || dp.back() < arr[i])
        {
            dp.push_back(arr[i]);
        }
        else
        {
            int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[idx] = arr[i];
        }
    }

    cout << dp.size();

    return 0;
}