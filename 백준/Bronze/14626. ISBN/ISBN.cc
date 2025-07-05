#include <iostream>
#include <string>

using namespace std;


int main() {
	string ISBN;
	int index, index_weight , sum = 0;

	cin >> ISBN;

	for (int i = 0; i < 13; i++) {

		if (!isdigit(ISBN[i])) {
			index = i;

			if (i % 2 == 0) index_weight = 1;
			else index_weight = 3;

			continue;
		}

		int a = ISBN[i] - '0';

		if (i % 2 == 0) a *= 1;
		else a *= 3;

		sum += a;
	}

	int i;
	for (i = 0; i < 13; i++) {
		sum += i * index_weight;

		if (sum % 10 == 0) {
			break;
		}
		else sum -= i * index_weight;
	}

	cout << i << endl;

	return 0;
}
