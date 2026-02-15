#include <iostream>
#include <stack>

using namespace std;

bool check(string str);

int main()
{

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        string str;
        cin >> str;

        if (check(str))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

bool check(string str)
{
    stack<char> st;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            st.push(str[i]);
        }
        else
        {
            if (st.empty())
                return 0;
            else
            {
                st.pop();
            }
        }
    }

    if (st.empty())
        return 1;
    else
        return 0;
}