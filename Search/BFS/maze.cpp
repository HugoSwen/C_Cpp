#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 105;

int n, m;
int maze[N][N], dtc[N][N];
queue<PII> q;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// maze[N][N] 记录迷宫
// dtc[N][N] 记录当前第一次搜索到的点距离出发点的最短距离
// q 记录当前需要往后扩展的点
// dx dy 存储当前待扩展的点需要对坐标的处理

void bfs()
{
    memset(dtc, -1, sizeof dtc); // 初始化为-1, 标记未搜索到
    dtc[1][1] = 0;               // 出发点与自身的距离为0
    q.push({1, 1});              // push出发点, 即当前待扩展点

    while (!q.empty())
    {
        auto h = q.front(); // 记录队首元素
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = h.first + dx[i], y = h.second + dy[i];                                  // 当前待扩展的点可以扩展到的坐标
            if (x >= 1 && x <= n && y >= 1 && y <= m && maze[x][y] == 0 && dtc[x][y] == -1) // 坐标在范围内、可以走且没走过
            {
                dtc[x][y] = dtc[h.first][h.second] + 1; // 扩展点到出发点的距离
                q.push({x, y});                         // 将扩展点push队列, 待下一步扩展
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &maze[i][j]);

    bfs();

    cout << dtc[n][m];

    return 0;
}