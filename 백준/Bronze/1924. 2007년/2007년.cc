#include <iostream>
#include <string>
using namespace std;

int main()
{
    string week[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int x, y, day = 0;
    cin >> x >> y;

    // 전 월까지 더한 값
    for (int i = 0; i < x - 1; i++)
    {
        day += days[i];
    }

    day += y - 1; // 1월 1일이 0이 나오도록

    day %= 7; // 7로 나눈 나머지

    cout << week[day];

    return 0;
}