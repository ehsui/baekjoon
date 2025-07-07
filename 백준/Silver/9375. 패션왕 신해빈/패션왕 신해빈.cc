#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;


int main() {
	string current_first, current_second;
	int T, n;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		unordered_map<string, int> wear;
		unordered_map<string, int>::iterator it;

		cin >> n;

		
		for (int j = 0; j < n; j++)
		{
			// Input ex) hat headgear
			cin >> current_first >> current_second;

			it = wear.find(current_second);

			// not choose도 있기 때문에 2로 설정
			if (it == wear.end()) wear.insert({ current_second, 2 });
			else wear[current_second] += 1;

		}

		int answer = 1;


		for (auto iter = wear.begin(); iter != wear.end(); ++iter)
		{		
			answer *= iter->second;
		}

		answer -= 1;

		std::cout << answer << "\n";
	}

	return 0;
}
