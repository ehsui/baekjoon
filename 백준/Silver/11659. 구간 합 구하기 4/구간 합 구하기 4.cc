#include <iostream>
#include <vector>

using namespace std;


vector <long> arr, sumArr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, temp, start, end;
	long answer;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);

		if (i == 0) sumArr.push_back(arr[0]);
		else sumArr.push_back(sumArr[i - 1] + arr[i]);
	}

	for (int i = 0; i < M; i++) {
		cin >> start >> end;

		if (start == 1) answer = sumArr[end - 1];
		else answer = sumArr[end - 1] -sumArr[start - 2];

		cout << answer << "\n";
	}

	return 0;
}
