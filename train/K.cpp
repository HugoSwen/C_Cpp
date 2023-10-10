#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

int T;
LL x, a, b;

int main()
{
    cin >> T;
    while (T --)
    {
        scanf("%lld%lld%lld", &x, &a, &b);
        LL res = 0;
        while (x)
        {
            LL e = x - 1, f = (x + a) / 2, g = int(sqrt(x + b));
            if (e <= f && e <= g)
                x = e;
            else if (f <= e && f <= g)
                x = f;
            else
                x = g;
            res++;
        }
        printf("%lld\n", res);
    }
    return 0;
}