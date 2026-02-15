#include <iostream>

using namespace std;

void back(int depth, int prev);
int num[6], k, arr[13];

int main()
{

    while (1)
    {
        cin >> k;
        if (k == 0)
            return 0;

        for (int i = 0; i < k; i++)
        {
            cin >> arr[i];
        }

        back(0, -1);
        cout << "\n";
    }
}

void back(int depth, int prev)
{

    if (depth == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << num[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = prev + 1; i < k; i++)
    {
        num[depth] = arr[i];
        back(depth + 1, i);
    }
}