#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
typedef pair<int, int> PII;

int hs[N], sum[N]; // 对应的人的收入金额 对应的人抢到红包个数
int k;             // 总人数
PII p[N];          // 人编号和收入金额对

int main()
{
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int cnt, w, h; // 发出总个数 抢到红包的人 抢到的金额
        scanf("%d", &cnt);
        while (cnt--)
        {
            scanf("%d%d", &w, &h);
            hs[w] += h, sum[w]++; // 对应的人增加
            hs[i] -= h;           // 发出红包的人减少
        }
    }
    for (int i = 1; i <= k; i++) // 将人编号和收入金额配对存储
        p[i].first = i, p[i].second = hs[i];

    sort(p + 1, p + k + 1, [](pair<int, int> a, pair<int, int> b)
         {
        if (a.second != b.second)
            return a.second > b.second;
        else
        {
            if (sum[a.first] !=  sum[b.first])
                return sum[a.first] > sum[b.first];
            else return a.first < b.first;
        } }); // 匿名cmp函数

    for (int i = 1; i <= k; i++)
        printf("%d %.2f\n", p[i].first, (float)p[i].second / 100);
    return 0;
}
