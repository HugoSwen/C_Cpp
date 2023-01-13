/*
 * 高精度
 */
#include <iostream>
#include <vector>
using namespace std;

const int N = 5005;
int primes[N], cnt; // 存储1~n中的所有质数
int sum[N];         // 结果中每个质数出现的次数
bool st[N];         // 筛质数的标志

vector<int> mul(vector<int> a, int b) // 高精度乘法
{
    vector<int> c;
    int t = 0;
    for (int i = 0, t = 0; i < a.size() || t; i++)
    {
        if (i < a.size())
            t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }

    return c;
}

void get_primes(int n) // 线性筛法筛出1~n中所有的质数
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int getnp(int n, int p) // 求得n!中质因子p有多少个
{
    int res = 0;
    while (n)
    {
        res += n / p;
        n /= p;
    }

    return res;
}

int main()
{
    int a, b;
    cin >> a >> b;

    get_primes(a);

    for (int i = 0; i < cnt; i++)
    {
        int p = primes[i];
        sum[i] = getnp(a, p) - getnp(a - b, p) - getnp(b, p); // 约分后每个质数出现的次数
    }

    vector<int> res;
    res.push_back(1);

    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < sum[i]; j++)
            res = mul(res, primes[i]);

    for (int i = res.size() - 1; i >= 0; i--)
        printf("%d", res[i]);

    return 0;
}