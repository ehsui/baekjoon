#include <iostream>
#include <vector>

using namespace std;


int main() {
	int N, K, current_coin, answer = 0, current_coin_count;
	vector<int> coin;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> current_coin;

		coin.push_back(current_coin);
	}

	while (true) {
		current_coin = coin[N - 1];
		current_coin_count = K / current_coin;

		answer += current_coin_count;

		K -= current_coin * current_coin_count;

		if (K == 0) break;
		if (N == 0) break;
		
		N--;
	}

	cout << answer;

	return 0;
}
