#include <iostream>
#include <string>

using namespace std;

int main()
{

    int N, M;
    string str, nstr;

    cin >> N >> M >> str;

    nstr = "IOI";
    for (int i = 1; i < N; i++)
    {
        nstr += "OI";
    }

    int index = str.find(nstr);
    int answer = 0;

    for (int pos = index; pos != string::npos; pos = str.find(nstr, pos + 1))
    {
        answer++;
    }

    cout << answer;

    return 0;
}