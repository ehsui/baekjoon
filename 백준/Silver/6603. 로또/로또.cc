#include <iostream>
#include <vector>

using namespace std;

int k, Selected[7], S[13];
void back(int depth, int start);

int main()
{

    int tmp;

    while (1)
    {

        cin >> k;

        if (k == 0)
            return 0;

        for (int i = 0; i < k; i++)
        {
            cin >> S[i];
        }

        back(0, 0);

        cout << "\n";
    }
    return 0;
}

void back(int depth, int start)
{

    if (depth == 6)
    {
        for (int i = 0; i < 5; i++)
        {
            cout << Selected[i] << " ";
        }
        cout << Selected[5] << "\n";
        return;
    }

    for (int i = start; i < k; i++)
    {
        Selected[depth] = S[i];
        back(depth + 1, i + 1);
    }
}