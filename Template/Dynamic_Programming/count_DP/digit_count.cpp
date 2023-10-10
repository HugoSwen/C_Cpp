#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long LL;

// 得到d中下标从b到a表示的数字
int get(vector<int> &d, int a, int b)
{
    int res = 0;
    for (int i = a; i >= b; i--)
        res = res * 10 + d[i];
    return res;
}

// 统计1~n中x出现的次数
LL count(int n, int x)
{
    vector<int> d;
    while (n) // 将n拆开方便统计
        d.push_back(n % 10), n /= 10;
    n = d.size();

    LL res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (x) // 当x > 0时
        {
            // 左边取 [0, get(d, n - 1, i + 1) - 1]，共 get(d, n - 1, i + 1) 次
            res += get(d, n - 1, i + 1) * pow(10, i); // 右边取 [0, 10^i - 1]，共 10^i 次

            // 左边取 get(d, n - 1, i + 1)，共 1 次
            if (d[i] == x)
                res += get(d, i - 1, 0) + 1; // 右边取 [0, get(d, i - 1, 0)]，共 get(d, i - 1, 0) + 1 次
            else if (d[i] > x)
                res += pow(10, i); // 右边取 [0, 10^i - 1]，共 10^i 次
            // 当d[i] < x 次数为0，不需要操作
        }
        else //  当x == 0时
        {
            if (i < n - 1) // 首位不可能为0，不需要计算
            {
                // 左边取 [1, get(d, n - 1, i + 1) - 1]，共 get(d, n - 1, i + 1) - 1 次
                res += (get(d, n - 1, i + 1) - 1) * pow(10, i); // 右边取 [0, 10^i - 1]，共 10^i 次

                // 右边取 get(d, n - 1, i + 1)，共 1 次
                if (d[i] == 0)
                    res += get(d, i - 1, 0) + 1; // 右边取 [0, get(d, i - 1, 0)]，共 get(d, i - 1, 0) + 1 次
                else if (d[i] > 0)
                    res += pow(10, i); // 右边取 [0, 10^i - 1]，共 10^i 次
            }
        }
    }

    return res;
}

int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b), a || b)
    {
        if (a > b)
            swap(a, b);
        for (int i = 0; i <= 9; i++)
            printf("%lld ", count(b, i) - count(a - 1, i)); // [1, b] 中i的个数减去 [1, a-1] 中i的个数即[a, b]中i的个数
        cout << endl;
    }

    return 0;
}