#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int M, N, k = 0;

    cin >> M >> N;
    
    int* ary = new int[N + 1];

    for (int i = 2; i < N + 1; i++) {
        ary[i] = i;
    }
    
    for (int i = 2; i < N + 1; i++) {
        if (ary[i] == 0) continue;

        for (int j = i * 2; j < N + 1; j += i) {
            ary[j] = 0;
        }
    }

    for (int i = M; i < N + 1; i++) {
        if(ary[i] != 0) cout << ary[i] << endl;
    }

    return 0;
}