#include <iostream>
using namespace std;

const int N = 1e5 + 10, M = (1 << 20) + 10;

int n, m, x;
int last[M], maxL[N];
// last[i] 记录并更新i最后一次出现的位置（至少2^20的空间）
// maxL[R] 记录右边界为R时，符合题目条件的左边界的最大位置

int main()
{
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        maxL[i] = max(maxL[i - 1], last[a ^ x]); // 当前位置为右边界，需要找到与它匹配的数字的最新位置与前一位的maxL取大
        last[a] = i;                             // 更新数字a的位置
    }

    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%s\n", l <= maxL[r] ? "yes" : "no"); // 只要l <= maxL[r]，就一定满足条件
    }

    return 0;
}