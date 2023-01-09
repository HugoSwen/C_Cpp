/*
 * 二分答案+数学计算
 */
#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;

int n, m;
int A[N], B[N];

bool check(int x)
{
    LL res = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] >= x) // 不小于x才能被选择
        {
            int t = (A[i] - x) / B[i] + 1; // Ai被选择的次数
            res += t;
        }
    }

    return res >= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%d%d", &A[i], &B[i]);

    int l = 0, r = 1e6;
    while (l < r) // 二分出满足可选择次数不小于m的最后一次升级增加的攻击力
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    LL res = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] >= l) // 不小于最小增加攻击力才能被选择
        {
            int t = (A[i] - l) / B[i] + 1; // Ai被选择的次数
            cnt += t;                      // 累加总次数
            int end = A[i] - (t - 1) * B[i];
            res += (LL)(A[i] + end) * t / 2; // 等差数列前n项和
        }
    }

    cout << res - (cnt - m) * l; // 最小攻击力有可能被多加了，这里需要减去多加的次数 * 最小攻击力
    return 0;
}