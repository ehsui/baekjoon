#include <iostream>
#include <string.h>
using namespace std;

long long P(int k);
long long cache[101] = {-1};

int main()
{
    memset(cache, -1, sizeof(cache));

    int T, N;

    cin >> T;

    cache[1] = 1;
    cache[2] = 1;
    cache[3] = 1;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        long long result = P(N);
        cout << result << "\n";
    }
    return 0;
}

long long P(int k)
{
    if (cache[k] == -1)
    {
        return cache[k] = P(k - 2) + P(k - 3);
    }
    else
        return cache[k];
}