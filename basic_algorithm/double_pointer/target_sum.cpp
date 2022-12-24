// 查找两数组某两个位置数字和为目标值（答案唯一）
#include <iostream>
using namespace std;

const int N = 100010;

int n, m, x;
int A[N], B[N];

int main()
{
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];

    for (int i = 0, j = m - 1; i < n; i++)
    {
        while (j >= 0 && A[i] + B[j] > x) // 使j成为使A[i]+B[j]当前达到小于等于x的最大值的位置
            j--;
        if (A[i] + B[j] == x)
            cout << i << ' ' << j;
    }
    return 0;
}