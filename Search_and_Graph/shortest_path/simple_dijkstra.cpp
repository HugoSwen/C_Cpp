#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dtc[N];
bool st[N];
// g[N][N] 用邻接矩阵存储稠密图
// dtc[N] 记录出发点到每个节点的最短距离
// st[N] 记录每个节点是永久标号还是临时标号

int dijkstra()
{
    // 初始化出发点到每个点的最短距离 dtc[1] = 0, dtc[i] = INF
    memset(dtc, 0x3f, sizeof dtc);
    dtc[1] = 0;

    for (int i = 0; i < n - 1; i++) // n - 1次遍历
    {
        int t = -1;                  // 找到第一个临时标号节点的媒介
        for (int j = 1; j <= n; j++) // 遍历节点 找到临时标号节点中距离最小的节点
        {
            if (!st[j] && (t == -1 || dtc[t] > dtc[j]))
                t = j;
        }

        st[t] = true; // 将该节点改为永久标号

        for (int j = 1; j <= n; j++) // 用刚得到的永久标号节点的距离更新其他节点的距离(实际只更新了相邻的临时标号节点)
            dtc[j] = min(dtc[j], dtc[t] + g[t][j]);
    }

    // 若到终点的距离为无穷大则表示无法抵达
    return dtc[n] == 0x3f3f3f3f ? -1 : dtc[n];
}

int main()
{
    memset(g, 0x3f, sizeof g); // 初始化任意两点间距离为INF

    cin >> n >> m;
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x][y] = min(g[x][y], z); // 存储两点间距离 若该位已存储过则取小
    }

    cout << dijkstra() << endl;
    return 0;
}