#include <iostream>
#include <cstring>

using namespace std;

int Memoization0(int N);
int Memoization1(int N);

int cache0[41];
int cache1[41];

int main() {
	int T, N, answer_first, answer_second;

	cin >> T;

	memset(cache0, -1, sizeof(cache0));
	memset(cache1, -1, sizeof(cache1));

	for (int i = 0; i < T; i++) {
		cin >> N;

		cout << Memoization0(N) << " " << Memoization1(N) << "\n";
	}

	return 0;
}

int Memoization0(int N) {

	if (N < 0) return 0;

	if (cache0[N] != -1) {
		return cache0[N];
	}
	else 
	{
		if (N == 0) return 1;
		else if (N == 1) return 0;
		else return cache0[N] = Memoization0(N - 1) + Memoization0(N - 2);
	}

}


int Memoization1(int N) {

	if (N <= 0) return 0;

	if (cache1[N] != -1) return cache1[N];
	else 
	{
		if (N == 1) return 1;
		else return cache1[N] = Memoization1(N - 1) + Memoization1(N - 2);
	}
}