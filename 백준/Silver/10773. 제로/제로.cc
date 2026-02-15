#include <iostream>
#include <stack>

using namespace std;

int main()
{

    int K, tmp;
    stack<int> st;

    cin >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> tmp;

        if (tmp == 0)
        {
            st.pop();
        }
        else
        {
            st.push(tmp);
        }
    }

    int answer = 0;
    while (!st.empty())
    {
        answer += st.top();
        st.pop();
    }

    cout << answer;

    return 0;
}