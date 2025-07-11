#include <iostream>
#include <cstring>

using namespace std;

long long cache[1001];

long long SOF(int n);

int main() {
	int n;

	cin >> n;

	memset(cache, -1, sizeof(cache));
	cache[1] = 1;
	cache[2] = 2;

	cout << SOF(n) % 10007;

	return 0;
}

long long SOF(int n) {

	if (cache[n] != -1) return cache[n];
	else {

		cache[n] = SOF(n - 1) % 10007 + SOF(n - 2) % 10007;
		return cache[n];
	}
}