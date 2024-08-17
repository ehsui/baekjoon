#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, total = 0, middle = 0;
    int max = -4001, min = 40001;

    cin >> N;

    int array[8001] = { 0 };
    
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        total += input;
        array[input + 4000] += 1;

        if (input > max) max = input;
        if (input < min) min = input;
    }

    int count = 0;
    for (int i = 0; i < 8001; i++) {
        count += array[i];
        if (count >= (N + 1) / 2) {
            middle = i - 4000;
            break;
        }
    }

    int mode = 0;
    int maxFreq = 0;
    bool second = false;

    for (int i = 0; i < 8001; i++) {
        if (array[i] > maxFreq) {
            maxFreq = array[i];
            mode = i - 4000;
            second = false;
        }
        else if (array[i] == maxFreq && !second) {
            mode = i - 4000;
            second = true;
        }
    }

    double avg = (double)total / N;
    int roundedAvg;
    if (avg - std::floor(avg) < 0.5) {
        roundedAvg = floor(avg);
    }
    else {
        roundedAvg = ceil(avg);
    }

    cout << roundedAvg << "\n" << middle << "\n" << mode << "\n" << max - min;

    return 0;
}