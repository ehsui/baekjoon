#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string key, str;
    cin >> key >> str;

    vector<pair<char, int>> keyInfo;

    for (int i = 0; i < key.size(); i++)
    {
        keyInfo.push_back({key[i], i});
    }

    stable_sort(keyInfo.begin(), keyInfo.end());

    string *arr = new string[key.size()];

    for (int j = 0; j < key.size(); j++)
    {
        arr[j] = keyInfo[j].first;

        for (int i = 0; i < str.size() / key.size(); i++)
        {
            arr[j] += str[j * str.size() / key.size() + i];
        }
    }

    string *originalArr = new string[key.size()];

    for (int i = 0; i < key.size(); i++)
    {
        int originIndex = keyInfo[i].second;

        // 정렬된 배열의 내용을 원래 위치로 보냄
        originalArr[originIndex] = arr[i];
    }

    for (int i = 1; i <= str.size() / key.size(); i++)
    {
        for (int j = 0; j < key.size(); j++)
            cout << originalArr[j][i];
    }
    return 0;
}