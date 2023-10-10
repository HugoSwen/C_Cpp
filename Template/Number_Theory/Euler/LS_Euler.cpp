#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n, eu[N], primes[N], st[N], cnt;

void LS_Euler(int n)
{
    eu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            eu[i] = i - 1; // 质数的欧拉函数值等于自身减一
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] != 0)
                eu[primes[j] * i] = eu[primes[j]] * eu[i]; // pj不是i的最小质因子，因此pj * i多了pj这个质因子
            else
            {
                eu[primes[j] * i] = primes[j] * eu[i]; // 反之pj不增加pj * i的质因子
                break;
            }
        }
    }
}

int main()
{
    cin >> n;

    LS_Euler(n);

    long long res = 0;
    for (int i = 1; i <= n; i++)
        res += eu[i];

    cout << res;
    return 0;
}