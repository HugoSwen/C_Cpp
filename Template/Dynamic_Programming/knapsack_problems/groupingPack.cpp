/*
状态f[i][j]：从前i组中选，且总体积不大于j的选法的最大价值
状态转移方程：f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i][k]] + w[i][k]) k = 1,2,3,···,s[i]
优化后：     f[j] = max(f[j], f[j - v[i][k]] + w[i][k])                  k = 1,2,3,···,s[i]
*/
#include <iostream>
using namespace std;

const int N = 110;

int n, m;
int v[N][N], w[N][N], s[N];
int f[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j++)
            cin >> v[i][j] >> w[i][j];
    }

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 1; k <= s[i]; k++)
                if (v[i][k] <= j)
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

    cout << f[m] << endl;
    return 0;
}
