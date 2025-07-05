#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> Id_password;

int main() {
	int N, M;
	string Id, Password;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> Id >> Password;

		Id_password.insert({Id, Password});
	}

	map <string, string>::iterator it;
	for (int i = 0; i < M; i++) {
		cin >> Id;

		it = Id_password.find(Id);
		cout << it->second << "\n";
	}
	return 0;
}
