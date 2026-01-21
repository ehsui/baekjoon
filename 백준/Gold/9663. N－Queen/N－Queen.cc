#include <iostream>
#include <cmath>
using namespace std;

int N;
int col[15];
int total = 0;

bool check(int depth);
void search(int depth);

// col[i] = j의 의미: i번째 행(Row)의 j번째 열(Column)에 퀸이 있다.
int main()
{
    cin >> N;

    search(0);

    cout << total << "\n";

    return 0;
}

bool check(int depth)
{

    for (int i = 0; i < depth; i++)
    {
        // 같은 열에 있는지 확인
        if (col[i] == col[depth])
            return false;
        // 대각선에 있는지 확인
        if (abs(col[depth] - col[i]) == depth - i)
            return false;
    }

    return true;
}

void search(int depth)
{
    if (depth == N)
    {
        total++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        col[depth] = i;

        if (check(depth))
        {
            search(depth + 1);
        }
    }
}