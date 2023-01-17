/*
01背包优化多重背包
s = 1 + 2 + ... + 2^k + c;
*/
#include <iostream>
using namespace std;

const int N = 11000;

int n, m;
int v[N], w[N], cnt;
int f[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;

        int k = 1;
        while (k <= s) // 将s个物品拆分成logs组新物品
        {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if (s > 0)
        {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }

    for (int i = 1; i <= cnt; i++) // 对新物品作01背包处理
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}