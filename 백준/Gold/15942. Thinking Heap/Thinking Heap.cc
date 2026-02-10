#include <iostream>
#include <vector>

using namespace std;

int N, k, p;
vector<int> mheap;
vector<bool> used;
bool fillDes(int idx, int &next_des);

int main()
{

    cin >> N >> k >> p;

    mheap.assign(N + 1, 0);
    used.assign(N + 1, false);

    // 문제 조건 고정
    mheap[p] = k;
    used[k] = true;

    // 위쪽 채우기
    int parent = k - 1;

    for (int idx = p / 2; idx > 0; idx /= 2)
    {
        if (parent < 1) // k보다 작은 숫자가 모자르다면
        {
            cout << -1;
            return 0;
        }
        mheap[idx] = parent;
        used[parent] = true;
        parent--;
    }

    // 아래쪽 채우기
    int des = k;
    if (!fillDes(p, des))
    {
        cout << -1;
        return 0;
    }

    // 빈칸 채우기
    int small_val = 1;
    for (int i = 1; i <= N; i++)
    {
        if (mheap[i] == 0)
        {
            while (used[small_val])
                small_val++;
            mheap[i] = small_val;
            used[small_val] = true;
        }
    }

    // 출력
    for (int i = 1; i <= N; i++)
        cout << mheap[i] << "\n";

    return 0;
}

bool fillDes(int idx, int &next_des)
{
    int left = idx * 2;
    int right = idx * 2 + 1;

    // 왼쪽 자식 확인
    if (left <= N)
    {
        if (++next_des > N)
            return false; // K보다 큰 숫자가 모자라면 실패

        mheap[left] = next_des;
        used[next_des] = true;

        if (!fillDes(left, next_des))
            return false;
    }
    // 오른쪽 자식 확인
    if (right <= N)
    {
        if (++next_des > N)
            return false;

        mheap[right] = next_des;
        used[next_des] = true;

        if (!fillDes(right, next_des))
            return false;
    }
    return true;
}