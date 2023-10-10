/*
状态f[u][0]、f[u][1]：节点u不取 取的情况下的最大值
状态转移方程：
f[u][0] = 求和 max(f[j][0], f[j][1]), j 是 u 的子节点
f[u][1] = 求和 f[j][0],               j 是 u 的子节点
*/
#include <cstring>
#include <iostream>
using namespace std;

const int N = 6010;

int n;
int H[N], f[N][2];
int h[N], e[N], ne[N], idx;
bool has_father[N];

void add(int a, int b) // 邻接表存树
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) // 递归处理
{
    f[u][1] = H[u]; // 取该点

    for (int i = h[u]; i != -1; i = ne[i]) // 遍历该节点每一个子节点
    {
        int j = e[i];
        dfs(j);

        f[u][0] += max(f[j][0], f[j][1]); // 子节点取或不取的最大值
        f[u][1] += f[j][0];               // 子节点不能取
    }
}

int main()
{
    memset(h, -1, sizeof h); // 邻接表初始化

    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &H[i]);

    for (int i = 0; i < n - 1; i++)
    {
        int l, k;
        scanf("%d%d", &l, &k);
        add(k, l);            // 存入邻接表
        has_father[l] = true; // 节点l存在父节点
    }

    int root = 1;
    while (has_father[root]) // 找到最高父节点
        root++;

    dfs(root);

    cout << max(f[root][0], f[root][1]) << endl; // 只有取最高点和不取两种情况

    return 0;
}