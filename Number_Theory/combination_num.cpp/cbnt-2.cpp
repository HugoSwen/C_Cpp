#include <iostream>
using namespace std;

typedef long long LL;
const int N = 100010, P = 1e9 + 7;

int fact[N], infact[N];
// 阶乘   阶乘 mod P 的逆元

int qmi(int a, int k, int p)
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

int main()
{
    fact[0] = infact[0] = 1; // 0!=1, 1 mod P的逆元还是1
    for (int i = 1; i < N; i++)
    {
        fact[i] = (LL)fact[i - 1] * i % P;
        infact[i] = (LL)infact[i - 1] * qmi(i, P - 2, P) % P;
    }

    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", (LL)fact[a] * infact[b] % P * infact[a - b] % P); // 模两次防止三个数相乘溢出
    }

    return 0;
}