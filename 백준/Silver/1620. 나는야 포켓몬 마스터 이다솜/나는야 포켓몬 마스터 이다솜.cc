#include <iostream>
#include <string>

#include <unordered_map>

using namespace std;

unordered_map <int, string> Poket;
unordered_map <string, int> Poket2;


int main() {
	int N, M;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	string name;

	for (int i = 1; i <= N; i++) {
		cin >> name;
		Poket.insert({i, name});
		Poket2.insert({ name, i });
	}

	string q;
	unordered_map <int, string>::iterator it;
	unordered_map <string, int>::iterator it2;
	for (int i = 0; i < M; i++) {

		cin >> q;

		if (isdigit(q[0])) 
		{
			it = Poket.find(stoi(q));

			cout << it->second << '\n';
		}
		else
		{
			it2 = Poket2.find(q);
			cout << it2->second << '\n';
		}

	}
}
