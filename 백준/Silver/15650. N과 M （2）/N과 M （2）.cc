#include <iostream>

using namespace std;

void back(int depth, int before);
int N, M, answer[9];
bool isUsed[9] = {false};

int main()
{

    cin >> N >> M;

    back(0, 0);
}

void back(int depth, int before)
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

    for (int i = before + 1; i <= N; i++)
    {
        if (!isUsed[i])
        {
            answer[depth] = i;
            isUsed[i] = true;
            back(depth + 1, i);
            isUsed[i] = false;
        }
    }
}