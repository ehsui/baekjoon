#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	int T, n;

	cin >> T;

	for (int t = 0; t < T; t++) {

		cin >> n;

		vector<int> dp(n + 1);

		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2; //11, 2
		dp[3] = 4; //111, 12, 21, 3

		for (int i = 4; i < n + 1; i++) {
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}

		cout << dp[n] << '\n';
	}

	return 0;
}