#include <iostream>
using namespace std;

const int N = 1e6 + 10;
typedef long long LL;

LL f[N], ans;

int main()
{
    int n, k;
    cin >> n >> k;

    // 数位DP 多位数除个位数字，其余位均已计算过，利用这个特性优化
    for (int i = 1; i <= n; i++)
        f[i] = f[i / 10] + (i % 10 == k), ans += f[i];

    cout << ans;

    return 0;
}