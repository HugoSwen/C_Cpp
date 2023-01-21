/*
朴素版
状态f[i][j]：从前i个数中选且总和是j的方案数量
状态转移方程：f[i][j] = f[i - 1][j] + f[i][j - i];
f[i][j] = f[i - 1][j] + f[i - 1][j - i] + f[i - 1][j - 2i] + ··· + f[i - 1][j - ki]
f[i][j - i] =           f[i - 1][j - i] + f[i - 1][j - 2i] + ··· + f[i - 1][j - ki]
*/
#include <iostream>
using namespace std;

const int N = 1010, P = 1e9 + 7;

int n;
int f[N][N];

int main()
{
    cin >> n;

    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if (i <= j)
                f[i][j] = (f[i][j] + f[i][j - i]) % P;
        }

    cout << f[n][n] << endl;
    return 0;
}