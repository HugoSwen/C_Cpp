/*
状态f[i][j]：从(i, j)点出发能划到的最大区域数
状态转移方程：f[i][j] = max(f[i][j], f[a][b] + 1),   (a, b)是(i, j)四周比它低的点
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 305;

int r, c;
int h[N][N];
int f[N][N];

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dp(int x, int y)
{
    int &v = f[x][y];
    if (v != -1) // 保证每个状态只算一次
        return v;

    v = 1;                      // 至少经过自身1个区域
    for (int i = 0; i < 4; i++) // 枚举四个位置
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && a <= r && b >= 1 && b <= c && (h[x][y] > h[a][b])) // 符合条件
            v = max(v, dp(a, b) + 1);                                    // 更新f[x][y]的值
    }

    return v;
}

int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            scanf("%d", &h[i][j]);

    memset(f, -1, sizeof f);

    int res = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            res = max(res, dp(i, j));

    cout << res << endl;
    return 0;
}