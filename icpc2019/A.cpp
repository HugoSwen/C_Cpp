#include <bits\stdc++.h>
// #define x first
// #define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e3 + 10, mod = 1e9 + 7, dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
int n, m, g[N][N], in[N][N], out[N][N];
ll ans;
ll cnt[N][N][5];
queue<PII> q;

void bfs()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!in[i][j] && out[i][j])
            {
                cnt[i][j][1] = 1;
                q.push({i, j});
            }
    
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        int a = t.first, b = t.second;
        for (int i = 0; i < 4; i++)
        {
            int x = a + dx[i], y = b + dy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= m && g[x][y] - 1 == g[a][b])
            {
                cnt[x][y][2] = (cnt[x][y][2] + cnt[a][b][1]) % mod;
                cnt[x][y][3] = (cnt[x][y][3] + cnt[a][b][2]) % mod;
                cnt[x][y][4] = (cnt[x][y][4] + cnt[a][b][3] + cnt[a][b][4]) % mod;
                if (--in[x][y] == 0) q.push({x, y});
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!out[i][j]) ans = (ans + cnt[i][j][4]) % mod;
}

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &g[i][j]);
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int a = i + dx[k], b = j + dy[k];
                if (a >= 1 && a <= n && b >= 1 && b <= m)
                {
                    if (g[a][b] + 1 == g[i][j])
                        in[i][j]++;
                    else if (g[a][b] - 1 == g[i][j])
                        out[i][j]++;
                }
            }
        }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cout << in[i][j] << " ";
    //     cout << endl;
    // }
    bfs();
    printf("%lld", ans);
}

int main()
{
    int T;
    // cin >> T;
    T = 1;
    while (T--)
        solve();

    return 0;
}
