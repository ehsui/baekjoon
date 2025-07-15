#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long find_k(vector<long> v, long k);

int main() {
	long N, M, tmp;
	vector<long> v;
	cin >> N >> M;

	for (long i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	cout << find_k(v, M);

	return 0;
}

// 정렬된 vector와 k값을 받아 잘라야 하는 값 출력
long find_k(vector<long> v, long k) {
	long result = 0;
	long left = 0; long right = v.back();

	while (left <= right) {

		// mid = 설정해볼 높이
		long H = (left + right) / 2;

		// 얻은 나무
		long tree = 0;
		for (int i = 0; i < v.size(); i++) {
			if(H < v[i]) tree += v[i] - H;
		}

		if (k <= tree) {
			left = H + 1;
			result = H;
		}
		else if (k > tree) {
			right = H - 1;
		}
	}

	return result;
}