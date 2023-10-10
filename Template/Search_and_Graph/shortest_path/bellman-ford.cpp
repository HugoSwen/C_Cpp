#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 1e4 + 10;

int n, m, k;
int dist[N], backup[N];
struct Edge
{
    int a, b, w;
} edges[M];

int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++)
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }

    return dist[n];
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    int t = bellman_ford();

    if (t > 0x3f3f3f3f / 2)
        puts("impossible");
    else
        cout << t << endl;

    return 0;
}