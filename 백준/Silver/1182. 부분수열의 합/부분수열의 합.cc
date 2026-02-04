#include <iostream>

using namespace std;

void back(int idx, int sum);
int N, S, arr[21], result = 0;

int main()
{

    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    back(0, 0);

    // 공집합 고려
    if (S == 0)
        result--;

    cout << result << "\n";
    return 0;
}

void back(int idx, int sum)
{
    if (idx == N)
    {
        if (sum == S)
            result++;
        return;
    }

    // 현재 원소를 포함하는 경우
    back(idx + 1, sum + arr[idx]);

    // 현재 원소를 포함하지 않는 경우
    back(idx + 1, sum);
}