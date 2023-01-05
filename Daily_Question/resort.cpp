/*
 * 求若干个给定区间内数字之和的和的另一种思路：数字×该数字被计算个数
 * 差分+排序不等式
 */
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;

int a[N], s[N], cnt[N];

int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }

    cin >> m;
    while (m--)
    {
        int L, R;
        scanf("%d%d", &L, &R);
        cnt[L]++, cnt[R + 1]--; // 处理差分数组
    }

    for (int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1]; // 通过差分数组计算每个数字被计算次数

    LL s1 = 0;
    for (int i = 1; i <= n; i++) // 也可以用前缀和的方法求
        s1 += (LL)a[i] * cnt[i];

    sort(cnt + 1, cnt + n + 1);
    sort(a + 1, a + n + 1);

    LL s2 = 0;
    for (int i = n; i >= 0 && cnt[i]; i--)
        s2 += (LL)a[i] * cnt[i];

    cout << s2 - s1;

    return 0;
}