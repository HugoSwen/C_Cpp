/*
状态f[i]：以第i个数为结尾的最长上升子序列的长度
状态转移方程：f[i] = max(1, f[j] + 1) j = 1,2,···, i - 1 且 a[j] < a[i]
*/
#include <iostream>
using namespace std;

const int N = 1010;

int n;
int a[N], f[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
    {
        f[i] = 1; // a[i]本身
        for (int j = 1; j < i; j++)
            if (a[j] < a[i]) // 有比a[i]小的才能取大
                f[i] = max(f[i], f[j] + 1);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i]);

    cout << res << endl;
    return 0;
}