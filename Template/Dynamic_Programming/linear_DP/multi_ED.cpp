#include <iostream>
using namespace std;

const int N = 15, M = 1010;

int n, m, lim;
char a[M][N];
int f[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i] + 1;

    // 初始化
    for (int i = 0; i < N; i++)
        f[0][i] = i;
    for (int i = 0; i < N; i++)
        f[i][0] = i;

    while (m--)
    {
        int res = 0;
        cin >> a[0] + 1 >> lim;
        for (int i = 1; i <= n; i++) // 枚举所有字符串
        {
            int j, k;
            for (j = 1; a[i][j] != '\0'; j++) // 状态计算
                for (k = 1; a[0][k] != '\0'; k++)
                {
                    f[j][k] = min(f[j - 1][k] + 1, f[j][k - 1] + 1);
                    if (a[i][j] == a[0][k])
                        f[j][k] = min(f[j][k], f[j - 1][k - 1]);
                    else
                        f[j][k] = min(f[j][k], f[j - 1][k - 1] + 1);
                }
            if (f[j - 1][k - 1] <= lim) // 不大于上限
                res++;
        }
        cout << res << endl;
    }

    return 0;
}