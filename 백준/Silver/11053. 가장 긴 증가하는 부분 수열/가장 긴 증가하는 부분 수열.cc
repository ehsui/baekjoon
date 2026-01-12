#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DP();
vector<int> arr;
int N, memory[1001];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, value;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        arr.push_back(input);
    }

    DP();
    value = 1;

    for (int i = 0; i < N; i++)
    {
        if (value < memory[i])
            value = memory[i];
    }
    cout << value;

    return 0;
}

void DP()
{
    for (int i = 0; i < N; i++)
    {
        memory[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                memory[i] = max(memory[i], memory[j] + 1);
            }
        }
    }
    return;
}