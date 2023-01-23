/*
状态f[i][j]：二进制数i表示走过的点，j表示该状态停留在那个点，该状态的最小值
状态转移方程：f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]), k是存在于i表示的非j的点
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 20, M = 1 << 20;

int n;
int w[N][N];
int f[M][N];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &w[i][j]);

    memset(f, 0x3f, sizeof f); // 初始化每个状态为无穷大

    f[1][0] = 0;                                                              // 出发点是0号点，状态值为0
    for (int i = 0; i < 1 << n; i++)                                          // 枚举所有状态
        for (int j = 0; j < n; j++)                                           // 枚举每一个点
            if (i >> j & 1)                                                   // 该点被走到过
                for (int k = 0; k < n; k++)                                   // 枚举剩余的每个点
                    if (i - (1 << j) >> k & 1)                                // 该点也走到过
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]); // 更新状态

    cout << f[(1 << n) - 1][n - 1] << endl; // 最终状态为n位1，且停留在 n - 1 号点
    return 0;
}