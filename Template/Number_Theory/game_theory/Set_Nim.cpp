#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 105, M = 1e4 + 10;

int n, k;
int s[N], SG[M];
// s[N] 可选择数字集合
// SG[M] 记录不同状态(数字)sg函数值

int sg(int x) // 求x的sg函数值
{
    if (SG[x] != -1) // 保证每个状态(数字)只计算一次sg函数值
        return SG[x];

    // 找到所有可达到的状态的sg函数值
    unordered_set<int> ac; // 存储可达到的状态的sg函数值
    for (int i = 0; i < k; i++)
        if (x >= s[i])
            ac.insert(sg(x - s[i]));

    // mex操作
    for (int i = 0;; i++) // 当前状态的sg函数值为不属于ac集合的最小的非负整数
        if (!ac.count(i))
            return SG[x] = i;
}

int main()
{
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> s[i];

    memset(SG, -1, sizeof SG);

    cin >> n;
    int res = 0;
    while (n--)
    {
        int x;
        cin >> x;
        res ^= sg(x);
    }

    if (res) // 异或值不为0则先手必胜
        puts("Yes");
    else
        puts("No");

    return 0;
}
