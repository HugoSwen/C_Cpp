#include <iostream>
using namespace std;

typedef long long LL;
const int N = 105;

LL a[N], b[N], s;

void down(int n)
{
    int t = n;
    if (2 * n <= s && a[2 * n] < a[t])
        t = 2 * n;
    if (2 * n + 1 <= s && a[2 * n + 1] < a[t])
        t = 2 * n + 1;

    if (t != n)
    {
        swap(a[t], a[n]);
        down(t);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        s = n;
        LL sum = 0;

        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for (int i = 1; i <= m; i++)
            scanf("%lld", &b[i]);

        for (int i = n / 2; i > 0; i--)
            down(i);

        for (int i = 1; i <= m; i++)
        {
            a[1] = b[i];
            down(1);
        }

        for (int i = 1; i <= n; i++)
            sum += a[i];

        printf("%lld\n", sum);
    }

    return 0;
}