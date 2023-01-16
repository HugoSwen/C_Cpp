#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;

int n, m;
bool rst[N], cst[N];
LL sum;
int rs, cs;
int main()
{
    cin >> n >> m;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        if (!rst[x])
            rs++, rst[x] = true;
        if (!cst[y])
            cs++, cst[y] = true;

        printf("%lld ", (LL)(n - rs) * (n - cs));
    }

    return 0;
}