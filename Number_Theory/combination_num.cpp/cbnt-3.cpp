/*
 * lucas定理O(logpN * p * logp)
 */
#pragma GCC optimize(2) // O2优化
#include <iostream>
using namespace std;

typedef long long LL;
int p;

int qmi(int a, int k)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }

    return res;
}

int C(int a, int b) // 单个组合数通项公式求法
{
    int res = 1;
    for (int i = b, j = a; i; i--, j--)
    {
        res = (LL)res * j % p;
        res = (LL)res * qmi(i, p - 2) % p;
    }

    return res;
}

int lucas(LL a, LL b)
{
    if (a < p && b < p) // a b均小于p直接用通项公式
        return C(a, b);
    return (LL)C(a % p, b % p) * lucas(a / p, b / p) % p; // 反之则用lucas定理迭代
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        LL a, b;
        cin >> a >> b >> p;
        cout << lucas(a, b) << endl;
    }

    return 0;
}