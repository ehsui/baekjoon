#include <iostream>

using namespace std;

bool isUsed[10] = {false};
int N, M, arr[10], selected[10];
void back(int depth, int idx);

int main()
{

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        arr[i] = i;

    back(0, 1);

    return 0;
}

void back(int depth, int idx)
{

    if (depth == M)
    {
        for (int i = 0; i < M - 1; i++)
        {
            cout << selected[i] << " ";
        }
        cout << selected[M - 1] << "\n";
        return;
    }

    for (int cur = idx; cur <= N; cur++)
    {
        selected[depth] = arr[cur];
        back(depth + 1, cur);
    }
}