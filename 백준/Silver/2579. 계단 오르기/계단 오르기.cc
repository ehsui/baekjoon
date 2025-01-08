#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
	int n;

	cin >> n;
	vector<int> stairs(n);
	vector <int> dp(n);

	for (int i = 0; i < n; i++) {
		cin >> stairs[i];
	}

	dp[0] = stairs[0]; //1칸인 경우 최댓값

	if (n == 0) {
		cout << dp[0];
		return 0;
	}

	dp[1] = stairs[0] + stairs[1]; //2칸인 경우 최댓값

	if (n == 1) {
		cout << dp[1];
		return 0;
	}

	dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]); //3칸인 경우 최댓값

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}

	cout << dp[n - 1];

	return 0;
}