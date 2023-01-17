/*
哈希表
*/
#include <iostream>
#include <cstring>
using namespace std;

typedef unsigned long long ULL;
const int N = 2e6 + 10, P = 131;

char s[N];
ULL hl[N], hr[N], p[N];
// hl[N] 记录所有前缀字符串哈希值
// hr[N] 记录所有后缀字符串哈希值
// p[N] 记录位数的权重

ULL get(ULL h[], int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    for (int i = 1;; i++)
    {
        cin >> s + 1;
        if (!strcmp(s + 1, "END"))
            break;

        int n = strlen(s + 1);
        for (int i = 2 * n; i > 0; i -= 2)
            s[i] = s[i / 2], s[i - 1] = 'z' + 1; // 每两个字符之间插入一个非字母字符，扩张字符串
        n *= 2;

        p[0] = 1;
        for (int i = 1, j = n; i <= n; i++, j--)
        {
            hl[i] = hl[i - 1] * P + s[i] - 'a' + 1;
            hr[i] = hr[i - 1] * P + s[j] - 'a' + 1; // 注意后缀字符串哈希值的计算
            p[i] = p[i - 1] * P;
        }

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int l = 0, r = min(i - 1, n - i);
            while (l < r) // 二分找到满足回文串的半径
            {
                int mid = l + r + 1 >> 1;
                if (get(hl, i - mid, i - 1) != get(hr, n + 1 - (i + mid), n + 1 - (i + 1)))
                    r = mid - 1;
                else
                    l = mid;
            }

            if (s[i - r] > 'z')
                res = max(res, r);
            else
                res = max(res, r + 1);
        }

        printf("Case %d: %d\n", i, res);
    }

    return 0;
}