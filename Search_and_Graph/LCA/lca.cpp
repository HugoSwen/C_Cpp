#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;

int n, m;
int p[N], l[N], r[N], dist[N];

void dfs(int u, int d)
{
    dist[u] = d;
    if (l[u] != -1)
        dfs(l[u], d + 1);
    if (r[u] != -1)
        dfs(r[u], d + 1);
}

int get_lca(int a, int b)
{
    if (dist[a] > dist[b])
        swap(a, b);
    while (dist[b] > dist[a])
        b = p[b];
    while (a != b)
        a = p[a], b = p[b];
    return a;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(l, -1, sizeof l);
        memset(r, -1, sizeof r);

        for (int i = 1; i <= n; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            l[i] = a, r[i] = b;
            if (a != -1)
                p[a] = i;
            if (b != -1)
                p[b] = i;
        }

        dfs(1, 0);

        while (m--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            int lca = get_lca(a, b);
            printf("%d\n", dist[a] + dist[b] - 2 * dist[lca]);
        }
    }
    return 0;
}