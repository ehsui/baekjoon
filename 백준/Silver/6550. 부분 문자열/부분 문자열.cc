#include <iostream>
#include <string>

using namespace std;

bool func(string s, string t);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;

    while (cin >> s >> t)
    {
        if (func(s, t))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}

bool func(string s, string t)
{
    for (int i = 0, j = 0; i < t.size(); i++)
    {
        // 같은 문자를 찾았으면
        if (s[j] == t[i])
        {
            // 모든 글자를 찾았으면
            if (s.size() == ++j)
                return true;
        }
    }

    return false;
}