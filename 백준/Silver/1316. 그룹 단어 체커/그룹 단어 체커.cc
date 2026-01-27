#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool fuc(string str);

int main()
{

    int N, total = 0;
    string str;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> str;

        if (fuc(str))
            total++;
    }

    cout << total << "\n";
    return 0;
}

bool fuc(string str)
{
    vector<char> dic;

    char word = str[0];
    dic.push_back(word);

    for (int i = 1; i < str.size(); i++)
    {
        if (word == str[i])
            continue;
        else
        {
            // 이미 나온 것이라면
            if (dic.end() != find(dic.begin(), dic.end(), str[i]))
            {
                return false;
            }

            // 이미 나온 것이 아니라면
            word = str[i];
            dic.push_back(word);
        }
    }

    return true;
}
