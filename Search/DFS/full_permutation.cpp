#include <iostream>
using namespace std;

const int N = 10;

int n, path[N];
bool sign[N];
// path[N]记录全排列路径
// sign[N]记录每个数字是否被用过

void dfs(int u)
{
    if (u == n) // u搜素到n的位置说明n个数都被用过
    {
        for (int i = 0; i < n; i++) // 输出结果
            printf("%d ", path[i]);
        printf("\n");
        return; // 并结束当前递归
    }

    for (int i = 1; i <= n; i++) // 每个位置都从1开始搜索
    {
        if (!sign[i]) // i未被用过
        {
            path[u] = i;     // 数据填充
            sign[i] = true;  // 标记已使用
            dfs(u + 1);      // 该位置搜索完毕，开始递归到下一个位置搜索
            sign[i] = false; // 搜索结束，恢复现场
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(0);
    return 0;
}