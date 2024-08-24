#include <iostream>
#include <stack>
using namespace std;


int main() {
    int n, k = 0, idx = 0, check = 0;

    cin >> n;

    char* output = new char[n * 2];
    int* number = new int[n];
    stack<int> st;

    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }

    int i = 1;

    while (i <= n || !st.empty()) {
        if (!st.empty() && st.top() == number[k]) {
            st.pop();
            output[idx++] = '-';
            k++;
        }
        else if (i <= n) {
            st.push(i);
            output[idx++] = '+';
            i++;
        }
        else {
            break;
        }
    }

    if (k != n) {
        cout << "NO" << endl;
    }
    else {
        for (int i = 0; i < idx; i++) {
            cout << output[i] << "\n";
        }
    }

    delete[] output;
    delete[] number;

    return 0;
}