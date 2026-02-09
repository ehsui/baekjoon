#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int N;

    cin >> N;

    vector<int> U;
    vector<int> sum;

    U.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> U[i];
    }

    sort(U.begin(), U.end());

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum.push_back(U[i] + U[j]);
        }
    }

    sort(sum.begin(), sum.end());

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            int target = U[i] - U[j];
            bool ex = binary_search(sum.begin(), sum.end(), target);

            if (ex)
            {
                cout << U[i];
                return 0;
            }
        }
    }

    return 0;
}