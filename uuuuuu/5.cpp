#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;

int n, m;
int fa[N], st[N];
vector<int> edge[N];
queue<int> q;

int main() {
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
        scanf("%d", &fa[i]);
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    memset(st, -1, sizeof st);
    q.push(1);
    st[1] = 0;

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        for (auto ed: edge[t])
        {
            while (st[ed] == -1)
            {
                st[ed] = st[t] + 1;
                q.push(ed);
                ed = fa[ed];
            }
        }
    }

    for (int i = 2; i <= n; i++)
        printf("%d ", st[i]);
    
    return 0;
}