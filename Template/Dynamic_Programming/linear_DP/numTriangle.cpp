/*
状态f[i][j]：从底部走到a[i][j]的路径数字之和的最大值
状态转移方程：f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j]
*/
#include <iostream>
using namespace std;

const int N = 505;

int n;
int f[N][N];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &f[i][j]);

    for (int i = n - 1; i >= 1; i--) // 倒推
        for (int j = 1; j <= i; j++)
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + f[i][j];

    cout << f[1][1] << endl;
    return 0;
}