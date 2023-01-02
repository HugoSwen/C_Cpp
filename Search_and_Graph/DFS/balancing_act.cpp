#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;

int n, ans = N;
int h[N], e[2 * N], ne[2 * N], idx;
bool st[N];

void add(int a, int b) // 添加一条有向边从a指向b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 返回以u为根节点的子树节点总数
int dfs(int u)
{
    st[u] = true; // 标记已搜索到

    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i]) // 遍历每个节点能达到的节点
    {
        int j = e[i]; // 当前位置存储的节点编号
        if (!st[j])   // 该节点未被搜索
        {
            int s = dfs(j);    // 搜索以该节点为根节点的子树节点总数
            res = max(res, s); // 找到子树最多的节点数
            sum += s;          // 累计搜索到的子树节点个数
        }
    }

    res = max(res, n - sum); // n - sum为无法搜索到子树节点个数

    ans = min(ans, res); // 找到结果的最小值

    return sum;
}

int main()
{
    memset(h, -1, sizeof h); // 初始化

    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a); // 添加两条有向边
    }

    dfs(1);

    cout << ans;
}