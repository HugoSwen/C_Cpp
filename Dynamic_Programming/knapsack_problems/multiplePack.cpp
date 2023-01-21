/*
朴素版
状态f[i][j]：从前i种物品中选，且总体积不大于j的选法最大价值
状态转移方程：f[i][j] = max(f[i - 1][j - k * v[i]] + k * w[i]) k = 0,1,2,···
*/
#include <iostream>
using namespace std;

const int N = 105;

int n, m;
int v[N], w[N], s[N];
int f[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j--)
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);

    cout << f[n][m] << endl;

    return 0;
}