/*
状态f[i][j]：第i列横向摆法的方案数
状态转移方程：f[i][j] += f[i - 1][k], k = 0,1,···,2^n - 1, 且 j & k == 0 && st[j | k]
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 12, M = 1 << 11;

int n, m;
long long f[N][M];
bool st[M];

int main()
{
    while (scanf("%d%d", &n, &m), n || m)
    {
        memset(f, 0, sizeof f); // 每次都要重置状态的值

        for (int i = 0; i < 1 << n; i++) // 枚举从[0, 2^n - 1]所有状态
        {
            st[i] = true;
            int cnt = 0; // 统计连续0的个数
            for (int j = 0; j < n; j++)
                if (i >> j & 1) // 当前行被占用
                {
                    if (cnt & 1) // 当前行下方连续0个数是奇数(cnt % 2)
                    {
                        st[i] = false; // 当前状态不合法
                        break;         // 无需继续遍历
                    }
                    cnt = 0; // 重置连续0个数
                }
                else       // 当前行未被占用
                    cnt++; // 连续0个数加1

            if (cnt & 1) // 处理循环正常结束时未处理的连续0个数
                st[i] = false;
        }

        f[0][0] = 1;                               // 第0列不能横放
        for (int i = 1; i <= m; i++)               // 从前往后枚举每一列
            for (int j = 0; j < 1 << n; j++)       // 枚举当前列的状态
                for (int k = 0; k < 1 << n; k++)   // 枚举前一列的状态
                    if ((j & k) == 0 && st[j | k]) // 状态合法
                        f[i][j] += f[i - 1][k];    // 累计方案数

        cout << f[m][0] << endl; // 最后一列不横着放的状态值即为答案
    }

    return 0;
}