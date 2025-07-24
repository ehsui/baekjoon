#include <iostream>
#include <cmath>

using namespace std;


int Z(int N, int zeroNumber, int r, int c);



int main() {
	int N, r, c;

	cin >> N >> r >> c;
	int size = pow(2, N);

	cout<< Z(N, 0, r, c);

	return 0;
}

int Z(int N, int zeroNumber, int r, int c) {

	// 단위 값
	int temp = pow(2, 2 * (N - 1));
	int half = pow(2, N - 1);

	if (c >= half) {
		// 4사분면
		if (r >= half) {
			r -= half;
			c -= half;
			zeroNumber += temp * 3;
		}
		// 1사분면
		else {

			c -= half;
			zeroNumber += temp;
		}
	}
	else {
		// 3사분면
		if (r >= half) {
			r -= half;
			zeroNumber += temp * 2;
		}
		// 2사분면
		else {
		}
	}

	if (N == 1) return zeroNumber;
	else return Z(N - 1, zeroNumber, r, c);
}
 