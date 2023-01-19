#include <iostream>
using namespace std;

const int N = 310;

int n;
int f[N][N];
int s[N];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    for (int len = 2; len <= n; len++)         // 枚举状态区间长度(长度为1时状态是0)
        for (int i = 1; i + len - 1 <= n; i++) // 枚举状态区间左边界
        {
            int l = i, r = i + len - 1;           // 当前状态左右边界
            f[l][r] = 1e9;                        // 初始化
            for (int k = i; k < i + len - 1; k++) // 枚举最后一次合并的分界线
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
        }

    cout << f[1][n] << endl;
    return 0;
}