#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long N, input;
	vector<long> v, v2;

	cin >> N;

	for (long i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
		v2.push_back(input);
	}

	// 정렬
	sort(v2.begin(), v2.end());

	// 중복 요소 제거
	v2.erase(unique(v2.begin(), v2.end()), v2.end());

	vector<long>::iterator it;
	for (long i = 0; i < N; i++) {
		it = lower_bound(v2.begin(), v2.end(), v[i]);
		cout << it - v2.begin() << " ";
	}

	return 0;
}