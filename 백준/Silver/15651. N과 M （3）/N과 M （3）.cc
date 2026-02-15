#include <iostream>

using namespace std;

void back(int depth);
int N, M, answer[9];

int main()
{

    cin >> N >> M;

    back(0);
}

void back(int depth)
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

    for (int i = 1; i <= N; i++)
    {
        answer[depth] = i;
        back(depth + 1);
    }
}
