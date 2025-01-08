#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	int n, result = 0, temp =0;

	cin >> n;
	vector<int> P(n);
	vector<int> d(n);

	for (int i = 0; i < n; i++) {
		cin >> P[i];
	}
	
	sort(P.begin(), P.end());

	d[0] = P[0];
	result += d[0];

	for (int i = 1; i < n; i++) {
		d[i] = d[i - 1] + P[i];
		result += d[i];
	}

	cout << result;

	return 0;
}