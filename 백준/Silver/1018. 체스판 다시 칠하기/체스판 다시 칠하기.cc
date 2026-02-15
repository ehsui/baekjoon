#include <iostream>

using namespace std;

int check(int startY, int startX);
char board[50][50];
int col, row;

int main()
{
    cin >> row >> col;

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cin >> board[r][c];
        }
    }

    int answer = 64;
    for (int r = 0; r <= row - 8; r++)
    {
        for (int c = 0; c <= col - 8; c++)
        {
            int tmp = check(r, c);

            if (answer > tmp)
            {
                answer = tmp;
            }
        }
    }

    cout << answer;

    return 0;
}

int check(int startY, int startX)
{
    int v1 = 0, v2 = 0;

    // v1 => W시작 /W가 (짝,짝) or (홀,홀) /B가 (짝,홀) or (홀,짝)
    // v2 => B시작 /B가 (짝,짝) or (홀,홀) /W가 (짝,홀) or (홀,짝)
    for (int r = startY; r < startY + 8; r++)
    {
        for (int c = startX; c < startX + 8; c++)
        {
            // 짞짞홀홀
            if (r % 2 == c % 2)
            {
                if (board[r][c] == 'B')
                {
                    v1 += 1;
                }
                else
                {
                    v2 += 1;
                }
            }
            else
            {
                if (board[r][c] == 'B')
                {
                    v2 += 1;
                }
                else
                {
                    v1 += 1;
                }
            }
        }
    }

    if (v1 >= v2)
    {
        return v2;
    }
    else
    {
        return v1;
    }
}