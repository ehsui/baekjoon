#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> memo;

int main()
{
    int N, max_value;

    cin >> N;
    vector<int> arr = vector<int>(N + 1);
    memo = vector<int>(N + 1);
    fill(memo.begin(), memo.end(), -1);

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    memo[0] = 0;
    memo[1] = arr[1];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            memo[i] = max(memo[i], memo[i - j] + arr[j]);
        }
    }

    cout << memo[N];
    return 0;
}
