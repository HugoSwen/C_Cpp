/*
f[i][j] 表示a[1~i], b[1~j] 的最长公共子序列长度
状态转移方程：f[i][j] = max(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1] + 1)
*/
#include <iostream>
using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

int main()
{
    cin >> n >> m >> a + 1 >> b + 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]); // 包含f[i - 1][j - 1]
            if (a[i] == b[j])                        // 两者相等时的状态计算
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }

    cout << f[n][m] << endl;

    return 0;
}