#include <iostream>

int main() {
	int N;
	int size[6];
	int T, P;
	int answer[3] = { 0 };

	std::cin >> N;

	for (int i = 0; i < 6; i++) {
		std::cin >> size[i];
	}

	std::cin >> T >> P;

	for (int i = 0; i < 6; i++) {
		answer[0] += size[i] / T;
		if (size[i] % T != 0) answer[0] += 1;
	}

	answer[1] = N / P;
	answer[2] = N % P;
	
	std::cout << answer[0] << std::endl;
	std::cout << answer[1] << " " << answer[2];
	return 0;
}