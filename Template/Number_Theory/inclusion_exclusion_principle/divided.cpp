#include <iostream>
using namespace std;

typedef long long LL;
const int N = 20;

int n, m, p[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> p[i];

    int res = 0;
    for (int i = 1; i < 1 << m; i++) // 用二进制枚举所有取舍情况
    {
        int t = 1, cnt = 0;         // t记录被选取集合对应的质数之积，cnt记录取了多少个集合
        for (int j = 0; j < m; j++) // 遍历当前情况每个集合的取舍情况
            if (i >> j & 1)         // 是1则被选取
            {
                cnt++;                // 选取集合次数+1
                if ((LL)t * p[j] > n) // 当被选取集合对应的质数之积超过n时则该情况集合交集元素个数为0，后续不做处理
                {
                    t = -1; // 标记不做处理
                    break;  // 无需继续遍历
                }
                t *= p[j]; // 满足条件，更新t的值继续遍历
            }

        if (t != -1) // 需要处理
        {
            if (cnt % 2) // 奇数做加法
                res += n / t;
            else // 偶数做减法
                res -= n / t;
        }
    }

    cout << res << endl;

    return 0;
}