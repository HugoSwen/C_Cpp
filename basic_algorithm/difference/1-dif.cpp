#include <iostream>
using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N]; // 默认前缀和与差分数每个元素都是0

void modify(int l, int r, int c) // 修改差分数组，使前缀和数组[l,r]区间内每个数+c
{
    b[l] += c;     // 使前缀和数组从l开始每个数+c
    b[r + 1] -= c; // 补丁：使前缀和数组从r+1开始每个数-c
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
        modify(i, i, a[i]); // 按前缀和数组的值初始化差分数组

    while (m--)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        modify(l, r, c); // 按对应结果修改差分数组
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + b[i]; // 修改前缀和数组为对应结果
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}