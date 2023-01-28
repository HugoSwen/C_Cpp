#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;

int n, m;
int h[N], ne[N], idx;
PII e[N];
int dist[N];
bool st[N];

void add(int a, int b, int w)
{
    e[idx] = {b, w}, ne[idx] = h[a], h[a] = idx++;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        int a = q.front();
        q.pop(), st[a] = false;

        for (int i = h[a]; i != -1; i = ne[i])
        {
            int b = e[i].first, w = e[i].second;
            if (dist[b] > dist[a] + w)
            {
                dist[b] = dist[a] + w;
                if (!st[b])
                    q.push(b), st[b] = true;
            }
        }
    }

    return dist[n];
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

    int t = spfa();

    if (t == 0x3f3f3f3f)
        puts("impossible");
    else
        cout << t << endl;

    return 0;
}