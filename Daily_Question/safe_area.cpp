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

    sum = (LL)n * n;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        if (!rst[x])
            sum = sum - n + cs, rs++, rst[x] = true;
        if (!cst[y])
            sum = sum - n + rs, cs++, cst[y] = true;

        printf("%lld ", sum);
    }

    return 0;
}