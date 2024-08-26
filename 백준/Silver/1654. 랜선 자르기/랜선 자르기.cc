#include <iostream>
#include <algorithm>
using namespace std;

bool fn(int param, int* lan, int N, int K) {
    long long cnt = 0;
    for (int i = 0; i < K; i++) {
        cnt += lan[i] / param;
    }

    return cnt >= N;
}

int main() {
    int N, K;

    cin >> K >> N;
    int* lan = new int[K];

    for (int i = 0; i < K; i++) {
        cin >> lan[i];
    }

    sort(lan, lan + K);

    long long min = 1;
    long long max = lan[K - 1];
    long long result = 0;

    while (min <= max) {
        long long param = (min + max) / 2;

        if (fn(param, lan, N, K)) {
            result = param;
            min = param + 1;
        }
        else {
            max =  param - 1;
        }
    }

    cout << result;

    delete[] lan;
    return 0;
}