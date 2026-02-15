#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int N, answer = 0;
    cin >> N;

    vector<pair<int, int>> time;

    pair<int, int> p;
    for (int i = 0; i < N; i++)
    {
        cin >> p.first >> p.second;
        time.push_back(p);
    }

    sort(time.begin(), time.end());

    int curEndTime = time[0].second;
    answer += 1;

    for (int i = 1; i < N; i++)
    {
        // 뒤에 시작한 게 더 빨리 끝나면
        if (curEndTime > time[i].second)
            curEndTime = time[i].second;
        // 끝나고 시작하는 회의가 있으면
        else if (curEndTime <= time[i].first)
        {
            curEndTime = time[i].second;
            answer++;
        }
    }

    cout << answer;

    return 0;
}