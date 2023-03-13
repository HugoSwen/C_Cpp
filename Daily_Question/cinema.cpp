#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 100;

int seat[N][N];
bool st[N][N];
queue<PII> q;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &seat[i][j]);

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (seat[i][j] && !st[i][j])
            {
                int cnt = 0;
                q.push({i, j});
                st[i][j] = true;

                while (q.size())
                {
                    auto qh = q.front();
                    q.pop();
                    cnt++;

                    int a = qh.first, b = qh.second;
                    for (int i = 0; i < 4; i++)
                    {
                        int x = a + dx[i], y = b + dy[i];
                        if (x >= 0 && x < n && y >= 0 && y < m && seat[x][y] && !st[x][y])
                        {
                            q.push({x, y});
                            st[x][y] = true;
                        }
                            
                    }
                }
                res = max(res, cnt);
            }
    cout << res;
    return 0;
}