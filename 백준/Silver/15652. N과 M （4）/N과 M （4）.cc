#include <iostream>

using namespace std;

void back(int depth, int prev);
int N, M, answer[9];

int main()
{

    cin >> N >> M;

    back(0, 1);
}

void back(int depth, int prev)
{

    if (depth == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = prev; i <= N; i++)
    {
        answer[depth] = i;
        back(depth + 1, i);
    }
}