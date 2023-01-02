/*
 * 思想：原始搜索，一个格子一个格子搜索
 */
#include <iostream>
using namespace std;

const int N = 20;

int n;
char pgm[N][N];
bool row[N], col[N], dg[N], adg[N];
// pgm记录方案
// row col dg adg 记录当前行 列 对角线 反对角线 是否被用过

void dfs(int x, int y, int s)
{
    if (y == n)
        y = 0, x++;

    if (x == n) // 所有行搜索结束
    {
        if (s == n) // 并且已经放了n个'Q', 则输出结果
        {
            for (int i = 0; i < n; i++)
                printf("%s\n", pgm[i]);
            printf("\n");
        }
        return; // 无论有没有放完, 所有行搜索结束就要结束递归
    }

    // 放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !adg[x - y + n])
    {
        pgm[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = adg[x - y + n] = true;
        dfs(x + 1, 0, s + 1); // 较dfs(x, y + 1, s + 1), 优化部分没必要搜索的情况
        pgm[x][y] = '.';
        row[x] = col[y] = dg[x + y] = adg[x - y + n] = false;
    }

    // 不放皇后
    dfs(x, y + 1, s);
}

int main()
{
    scanf("%d", &n);
    // 初始化
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pgm[i][j] = '.';

    dfs(0, 0, 0);

    return 0;
}