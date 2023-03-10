#include <iostream>
using namespace std;

const int N = 1010;

int n, m, q;
int a[N][N], b[N][N];

void modify(int x1, int y1, int x2, int y2, int c) // 修改前缀和数组，使其(x1,y1)-(x2,y2)区域内每个数+c
{
    b[x1][y1] += c;
    // 三部分补丁
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            modify(i, j, i, j, a[i][j]);
        }

    while (q--)
    {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        modify(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + b[i][j];
            printf("%d ", a[i][j]);
        }
        cout << endl;
    }

    return 0;
}