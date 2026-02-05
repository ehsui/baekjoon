#include <iostream>
#include <set>

using namespace std;

void Delete(int n);
void Insert(int n);
multiset<int> ms;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int k;
        cin >> k;

        ms.clear();

        for (int j = 0; j < k; j++)
        {
            char ch;
            int n;
            cin >> ch >> n;

            if (ch == 'D')
                Delete(n);
            else if (ch == 'I')
                Insert(n);
        }

        if (ms.size() == 0)
            cout << "EMPTY\n";
        else
            cout << *ms.rbegin() << " " << *ms.begin() << "\n";
    }

    return 0;
}

void Delete(int n)
{
    if (!ms.size())
        return;

    if (n == -1)
    {
        ms.erase(ms.begin());
    }
    else
    {
        auto it = ms.end();
        it--;
        ms.erase(it);
    }
}

void Insert(int n)
{
    ms.insert(n);
}
