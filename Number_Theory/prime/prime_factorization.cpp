#include <iostream>
using namespace std;

void factorize(int x)
{
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                x /= i;
                cnt++;
            }

            printf("%d %d\n", i, cnt);
        }
    }

    if (x > 1) // 大于sqrt(n)的最大质因子最多只有一个
        printf("%d %d\n", x, 1);
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int a;
        scanf("%d", &a);
        factorize(a);
        printf("\n");
    }

    return 0;
}