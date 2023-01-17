/*
优化版
状态转移方程：f[j] = max(f[j], f[j - v[i]] + w[i])
*/
#include <iostream>
using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &v[i], &w[i]);

    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++) // f[j - v[i]]是i行已经更新过的值，因此j需要从小到大枚举
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}