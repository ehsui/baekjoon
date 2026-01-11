#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, M, tmp;
    vector<int> arr;
    vector<bool> output;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        bool isFound = binary_search(arr.begin(), arr.end(), tmp);

        if (isFound)
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }

    return 0;
}