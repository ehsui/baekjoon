#include <iostream>
#include <vector>
using namespace std;

int S = 0;

void menu(string code)
{
	int number;

	if (code == "add")
	{
		cin >> number;
		S |= (1 << number);
	}
	else if (code == "check")
	{
		cin >> number;
		if (S & (1 << number)) {
			cout << 1 << "\n";
		}
		else cout << 0 << "\n";

	}
	else if (code == "remove") 
	{
		cin >> number;
		S &= ~(1 << number);
	}
	else if (code == "toggle")
	{
		cin >> number;
		S ^= (1 << number);
	}
	else if (code == "all")
	{
		S = (1 << 21) - 1;
	}
	else if (code == "empty")
	{
		S = 0;
	}
}

int main()
{
	int M;
	string code;

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> code;
		menu(code);
	}

	return 0;
}