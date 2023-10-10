#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 1e4, P = 131;

int n, m;
char str[N];
ULL h[N], p[N]; // h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k mod 2^64

// 计算子串 str[l ~ r] 的哈希值
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    int t;
    cin >> t;
    while (t --)
    {
        scanf("%s", str + 1);
        int n = strlen(str + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            h[i] = h[i - 1] * P + str[i];
            p[i] = p[i - 1] * P;
        }

        int res = 0;

        for (int i = 1; i < n; i++)
        {
            int nl = i, nr = i + 1;
            for (int l = i, r = i + 1; l >= 1 && r <= n; l--, r++)
            {
                if (get(l, nl) == get(nr, r))
                    res++, nl = l - 1, nr = r + 1;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}