#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long DP(int k);

int main()
{
    int N;
    long long result;

    cin >> N;
    vector<long long> memory = vector<long long>(N + 1);
    fill(memory.begin(), memory.end(), -1);

    // 기저
    memory[0] = 0;
    memory[1] = 1;
    memory[2] = 2;

    for (int i = 3; i <= N; i++)
    {
        memory[i] = (memory[i - 1] + memory[i - 2]) % 15746;
    }

    cout << memory[N];

    return 0;
}
