#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;

int n;
int h[N], ph[N], hp[N], tail, si;
// h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
// ph[k]存储第k个插入的点在堆中的位置
// hp[k]存储堆中下标是k的点是第几个插入的

// 交换两个点，及其映射关系
void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void up(int x)
{
    int t = x / 2;
    if (t && h[x] < h[t])
    {
        heap_swap(t, x);
        up(t);
    }
}

void down(int x)
{
    int t = x;
    if (2 * x <= tail && h[2 * x] < h[t])
        t = 2 * x;
    if (2 * x + 1 <= tail && h[2 * x + 1] < h[t])
        t = 2 * x + 1;

    if (t != x)
    {
        heap_swap(t, x);
        down(t);
    }
}

int main()
{
    scanf("%d", &n);

    while (n--)
    {
        char ope[5];
        int k, x;
        scanf("%s", ope);

        if (!strcmp(ope, "I"))
        {
            scanf("%d", &x);

            tail++, si++;
            h[tail] = x;
            ph[si] = tail;
            hp[tail] = si;

            up(tail);
        }
        else if (!strcmp(ope, "PM"))
            printf("%d\n", h[1]);
        else if (!strcmp(ope, "DM"))
        {
            heap_swap(1, tail);
            tail--;
            down(1);
        }
        else if (!strcmp(ope, "D"))
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, tail);
            tail--;
            down(k), up(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}