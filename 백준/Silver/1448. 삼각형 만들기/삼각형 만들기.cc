#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int N, tmp;

    cin >> N;

    vector<int> vec;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());

    for (int a = N - 1; a > 1; a--)
    {
        if (vec[a] < vec[a - 1] + vec[a - 2])
        {
            cout << vec[a] + vec[a - 1] + vec[a - 2];
            return 0;
        }
    }

    cout << -1;
    return 0;
}
