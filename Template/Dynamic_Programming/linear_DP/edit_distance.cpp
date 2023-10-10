/*
状态f[i][j]：将a[1~i] 变成 b[1~j] 的最少步骤
状态转移方程：f[i][j] = min(f[i][j - 1] + 1, f[i - 1][j] + 1, f[i - 1][j - 1] + 1/0)
*/
#include <iostream>
using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

int main()
{
    cin >> n >> a + 1 >> m >> b + 1;

    // 初始化操作
    for (int i = 0; i <= n; i++)
        f[i][0] = i;
    for (int i = 0; i <= m; i++)
        f[0][i] = i;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i][j - 1] + 1, f[i - 1][j] + 1); // 增：f[i][j - 1] + 1, 删：f[i - 1][j] + 1
            if (a[i] == b[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]); // a[i] == b[j] 改：f[i - 1][j - 1]
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1); // a[i] != b[j] 改：f[i - 1][j - 1] + 1
        }

    cout << f[n][m] << endl;
    return 0;
}