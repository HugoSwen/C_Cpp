#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;

int n, m;
int h[N], ne[M], idx;
PII e[M];
int dist[N];
bool st[N];

void add(int a, int b, int w)
{
    e[idx] = {b, w}, ne[idx] = h[a], h[a] = idx++;
}

int prim()
{
    memset(dist, 0x3f, sizeof dist);

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    int res = 0, cnt = 0;
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int dtc = t.first, ner = t.second;
        if (st[ner]) // 容余备份不做处理
            continue;
        st[ner] = true, cnt++, res += dtc; // 更新成永久节点

        for (int i = h[ner]; i != -1; i = ne[i])
        {
            int j = e[i].first, k = e[i].second;
            if (dist[j] > k)
            {
                dist[j] = k;
                heap.push({dist[j], j});
            }
        }
    }
    if (cnt < n)
        res = INF;
    return res;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        add(a, b, w), add(b, a, w);
    }

    int t = prim();

    if (t == INF)
        puts("impossible");
    else
        cout << t << endl;

    return 0;
}