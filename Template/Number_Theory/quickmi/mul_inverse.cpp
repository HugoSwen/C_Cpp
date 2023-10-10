#include <iostream>
using namespace std;

typedef long long LL;

int qmi(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (LL)res * a % p;
        b >>= 1;
        a = (LL)a * a % p;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, p;
        scanf("%d%d", &a, &p);
        if (a % p == 0) // a p 不互质则a不存在乘法逆元
            puts("impossible");
        else
            printf("%d\n", qmi(a, p - 2, p)); // a p 互质则a乘法逆元为a^p-2
    }

    return 0;
}