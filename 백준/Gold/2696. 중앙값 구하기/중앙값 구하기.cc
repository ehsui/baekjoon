#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int T, M, tmp;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        priority_queue<int> max_pq;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        vector<int> answer;

        cin >> M;

        for (int j = 0; j < M; j++)
        {
            cin >> tmp;

            if (max_pq.size() == min_pq.size())
            {
                max_pq.push(tmp);
            }
            else
            {
                min_pq.push(tmp);
            }

            if (min_pq.size() && min_pq.top() < max_pq.top())
            {
                int tmp = min_pq.top();
                int tmp2 = max_pq.top();

                min_pq.pop();
                max_pq.pop();

                min_pq.push(tmp2);
                max_pq.push(tmp);
            }

            if (j % 2 == 0)
            {
                answer.push_back(max_pq.top());
            }
        }

        cout << answer.size() << "\n";
        for (int k = 0; k < answer.size(); k++)
        {
            cout << answer[k] << " ";
            if ((k + 1) % 10 == 0)
                cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}