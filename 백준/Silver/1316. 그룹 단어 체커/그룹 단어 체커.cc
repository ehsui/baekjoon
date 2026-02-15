#include <iostream>

using namespace std;

int check(string str);

int main()
{
    int N, count = 0;
    string str;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        count += check(str);
    }

    cout << count;

    return 0;
}

int check(string str)
{
    int arr[26] = {0};

    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        arr[c - 'a'] += 1;
        if (i != 0 && str[i - 1] == str[i])
            continue;
        else
        {
            if (arr[c - 'a'] > 1)
            {
                return 0;
            }
        }
    }

    return 1;
}