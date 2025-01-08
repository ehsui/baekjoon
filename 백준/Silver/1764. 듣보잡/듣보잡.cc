#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main(){
	int n1, n2;
	string temp;

	cin >> n1 >> n2;

	vector<string> vec;

	map<string, int> map;
	
	for (int i = 0; i < n1; i++) {
		cin >> temp;
		map.insert(make_pair(temp, i));
	}


	for (int i = 0; i < n2; i++) {
		cin >> temp;

		if (!(map.find(temp) == map.end())) {
			vec.push_back(temp);

		}
	}

	cout << vec.size() << "\n";
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i]<<"\n";
	}
	return 0;
}