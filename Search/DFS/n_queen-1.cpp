/*
 * 思想：依据全排列，一层层搜索
 */
#include <iostream>
using namespace std;

const int N = 20;

int n;
char pgm[N][N];
bool col[N], dg[N], adg[N];
// pgm[N][N]记录方案
// col dg adg 记录某列某对角线某反对角线是否被使用过

void dfs(int r)
{
    if (r == n) // 行数等于n说明已经搜索完成
    {
        for (int i = 0; i < n; i++)
            printf("%s\n", pgm[i]);
        printf("\n");

        return;
    }

    for (int c = 0; c < n; c++) // 每一行从第0列开始搜索
    {
        if (!col[c] && !dg[r + c] && !adg[r - c + n]) // i列 r+c对角线 r-c+n反对角线都没有被使用过
        {
            pgm[r][c] = 'Q';                            // 放皇后
            col[c] = dg[r + c] = adg[r - c + n] = true; // 标记已使用
            dfs(r + 1);                                 // 搜索下一行
            pgm[r][c] = '.';                            // 恢复现场
            col[c] = dg[r + c] = adg[r - c + n] = false;
        }
    }
}

int main()
{
    scanf("%d", &n);
    // 初始化
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pgm[i][j] = '.';

    dfs(0);

    return 0;
}