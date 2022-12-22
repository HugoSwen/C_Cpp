#include <iostream>
using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

void modify(int l, int r, int c) // 修改差分数组
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
        modify(i, i, a[i]); // 初始化差分数组

    while (m--)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        modify(l, r, c); // 按对应结果修改差分数组
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + b[i];
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}