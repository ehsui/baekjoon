#include <iostream>

using namespace std;

int main()
{
    int N;

    cin >> N;

    int (*cost)[3] = new int[N + 1][3];
    int (*d)[3] = new int[N + 1][3];

    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    d[1][0] = cost[1][0];
    d[1][1] = cost[1][1];
    d[1][2] = cost[1][2];

    for (int i = 2; i <= N; i++)
    {
        d[i][0] = cost[i][0] + min(d[i - 1][1], d[i - 1][2]);
        d[i][1] = cost[i][1] + min(d[i - 1][0], d[i - 1][2]);
        d[i][2] = cost[i][2] + min(d[i - 1][0], d[i - 1][1]);
    }

    int tmp = min(d[N][1], d[N][2]);
    int answer = min(tmp, d[N][0]);

    cout << answer;

    return 0;
}