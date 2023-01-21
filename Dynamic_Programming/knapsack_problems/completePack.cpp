/*
朴素版
状态f[i][j]：从前i个物品中选，且总体积不大于j的选法的最大价值
状态转移方程：f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i])
f[i][j] = f[i - 1][j] + f[i - 1][j - v]+w + f[i - 1][j - 2v]+2w + ··· + f[i - 1][j - kv]+kw
f[i][j - v] =           f[i - 1][j - v]   + f[i - 1][j - 2v]+w  + ··· + f[i - 1][j - kv]+(k-1)w
*/
#include <iostream>
using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &v[i], &w[i]);

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]); // 写出f[i][j] 和 f[i][j - v[i]] 表达式，观察相似处
        }

    cout << f[n][m] << endl;

    return 0;
}