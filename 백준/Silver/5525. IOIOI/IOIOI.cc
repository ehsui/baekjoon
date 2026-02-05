#include <iostream>
#include <string>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    string str;

    cin >> N >> M >> str;

    int answer = 0;
    for (int i = 0; i < M; i++)
    {
        if (str[i] == 'I')
        {
            int k = 0;

            while (str[i + 1] == 'O' && str[i + 2] == 'I')
            {
                k++;
                if (k == N)
                {
                    answer++;
                    k--;
                }

                i += 2;
            }
        }
    }

    cout << answer;
}