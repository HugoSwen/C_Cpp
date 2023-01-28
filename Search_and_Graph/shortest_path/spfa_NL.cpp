#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;

int n, m;
int h[N], ne[N], idx;
PII e[N];
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int w)
{
    e[idx] = {b, w}, ne[idx] = h[a], h[a] = idx++;
}

bool spfa()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i), st[i] = true;

    while (q.size())
    {
        int a = q.front();
        q.pop(), st[a] = false;

        for (int i = h[a]; i != -1; i = ne[i])
        {
            int b = e[i].first, w = e[i].second;
            if (dist[b] > dist[a] + w)
            {
                cnt[b] = cnt[a] + 1;
                dist[b] = dist[a] + w;
                
                if (cnt[b] >= n)
                    return true;
                if (!st[b])
                    q.push(b), st[b] = true;
            }
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        add(a, b, w);
    }

    if (spfa())
        puts("Yes");
    else
        puts("No");

    return 0;
}