/*
 * 思想：原始搜索，一个格子一个格子搜索
 */
#include <iostream>
using namespace std;

const int N = 20;

int n;
char pgm[N][N];
bool row[N], col[N], dg[N], adg[N];

void dfs(int x, int y, int s)
{
    if (y == n) y = 0, x++;

    if (s == n)
    {
        for (int i = 0; i < n; i++)
            printf("%s\n", pgm[i]);
        printf("\n");

        return;
    }

    
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