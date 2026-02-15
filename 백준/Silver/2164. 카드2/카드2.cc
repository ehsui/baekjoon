#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    queue<int> q;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    int tmp;
    while (!q.empty())
    {
        if (q.size() == 1)
        {
            cout << q.front();
            return 0;
        }

        q.pop();
        q.push(q.front());
        q.pop();
    }
    return 0;
}