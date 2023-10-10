/*
 * φ(N) = N * (1 - 1/p1) * ··· * (1 - 1 / pk)
 * p1 ··· pk是N的质因子
 */
#include <iostream>
using namespace std;

int Euler(int x)
{
    long long res = x;
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
                x /= i;
            res = res * (i - 1) / i;
        }
    }
    if (x > 1)
        res = res * (x - 1) / x;
    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        scanf("%d", &a);
        printf("%d\n", Euler(a));
    }

    return 0;
}