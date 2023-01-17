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

    // f[0~m]默认为0
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--) // f[j - v[i]]是i - 1行未更新的数据，因此j需要从大到小枚举
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}