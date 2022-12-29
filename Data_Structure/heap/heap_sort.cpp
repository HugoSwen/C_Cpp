#include <iostream>
using namespace std;

const int N = 100010;

int n, m;
int h[N], tail;

void down(int x)
{
    int t = x;
    if (2 * x <= tail && h[2 * x] < h[t])
        t = 2 * x;
    if (2 * x + 1 <= tail && h[2 * x + 1] < h[t])
        t = 2 * x + 1;

    if (t != x)
    {
        swap(h[t], h[x]);
        down(t);
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    tail = n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);

    // O(n)建堆,可用数学归纳法证明n/2往后都没有子节点,即是完整的堆
    for (int i = n / 2; i; i--)
        down(i);

    while (m--)
    {
        printf("%d ", h[1]);

        h[1] = h[tail--];
        down(1);
    }

    return 0;
}