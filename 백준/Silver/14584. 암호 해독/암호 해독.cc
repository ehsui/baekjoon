#include <iostream>
#include <string>

using namespace std;

int main()
{

    string str, dic[20];
    int N;

    cin >> str >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> dic[i];
    }

    for (int k = 0; k < 26; k++)
    {

        for (int i = 0; i < N; i++)
        {
            if (str.find(dic[i]) != string::npos)
            {
                cout << str;
                return 0;
            }
        }

        for (int j = 0; j < str.size(); j++)
        {
            str[j]++;
            if (str[j] > 'z')
                str[j] -= 26;
        }
    }

    return 0;
}