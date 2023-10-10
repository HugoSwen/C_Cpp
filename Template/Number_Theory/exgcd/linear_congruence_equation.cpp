#include <iostream>
using namespace std;

typedef long long LL;

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }

    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int a, b, m, x, y;
        scanf("%d%d%d", &a, &b, &m);

        int d = exgcd(a, m, x, y);
        if (b % d == 0)
            printf("%d\n", (LL)x * (b / d) % m);
        else
            puts("impossible");
    }

    return 0;
}