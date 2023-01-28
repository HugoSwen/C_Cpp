#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;
const int N = 1.5e5 + 10;

int n, m;
int h[N], ne[N], idx;
PII e[N];
int dist[N];
bool st[N];
// 用邻接表存储稀疏图
// dtc[N] 记录出发点到每个节点的最短距离
// st[N] 记录每个节点是永久标号还是临时标号

void add(int a, int b, int c)
{
    e[idx] = {b, c}, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size())
    {
        auto t = heap.top(); // 找到临时标号节点中距离最小的点
        heap.pop();

        int dtc = t.first, ner = t.second;
        if (st[ner]) // 容余备份不做处理
            continue;
        st[ner] = true; // 更新成永久节点

        for (int i = h[ner]; i != -1; i = ne[i]) // 更新所有相邻的临时标号节点
        {
            int j = e[i].first, k = e[i].second;
            if (dist[j] > dtc + k)
            {
                dist[j] = dtc + k;
                heap.push({dist[j], j});
            }
        }
    }

    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
}

int main()
{
    memset(h, -1, sizeof h);

    cin >> n >> m;
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }

    cout << dijkstra() << endl;
    return 0;
}