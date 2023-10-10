#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], e[N], ne[N], idx, d[N]; // d[N]记录每个节点的入度
int q[N], qh = 1, qt = 0;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
    for (int i = 1; i <= n; i++) // 将所有入度为零的点入队
    {
        if (!d[i])
            q[++qt] = i;
    }

    while (qh <= qt)
    {
        int u = q[qh++];

        for (int i = h[u]; i != -1; i = ne[i]) // 删除该从该节点出发的所有边
        {
            int j = e[i];
            if (!(--d[j]))   // 删边后j的入度为零
                q[++qt] = j; // 将入度为零的点入队
        }
    }

    return qt == n; // 若有拓扑排序，则所有的点都应在队列中出现过
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);

    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b]++;
    }

    if (topsort())
    {
        for (int i = 1; i <= n; i++)
            printf("%d ", q[i]);
    }
    else
        puts("-1");

    return 0;
}