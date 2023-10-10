#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int tr[N];

inline int lowbit(int x)
{
    return x & -x;
}

void modify(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        modify(i, a);
    }

    while (m--)
    {
        int k, a, b;
        scanf("%d%d%d", &k, &a, &b);
        if (!k)
            printf("%d\n", query(b) - query(a - 1));
        else
            modify(a, b);
    }
    return 0;
}