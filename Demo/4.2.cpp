#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1010;

int n, m, d; // 点数 边数 终点编号
int tm[N];   // 存储到达每个地点的最短时间
int dist[N]; // 存储到达每个地点的最短距离
int pre[N];  // 存储到达每个地点的前一个地点
bool st[N];  // 记录地点是否被访问过

struct Edge
{
    int dest;  // 终点
    int time;  // 时间
    int dst;   // 距离
} graph[N][N]; // 用邻接矩阵存储图

void dijkstra() // dijkstra算法寻找最短路
{
    memset(tm, 0x3f, sizeof tm);     // 初始化到每个点的时间为无穷大
    memset(dist, 0x3f, sizeof dist); // 初始化到每个点的距离为无穷大

    tm[1] = 0;   // 学校为起点，到达学校的时间为0
    dist[1] = 0; // 学校为起点，到达学校的距离为0

    for (int i = 1; i <= n; i++)
    {
        int mintime = 0x3f3f3f3f;
        int u = 0;

        // 找到未访问的地点中时间最短的地点
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && tm[j] < mintime)
            {
                mintime = tm[j];
                u = j;
            }
        }

        if (u == 0 || u == d) // 找不到可达地点或已到达目的地
            break;
        st[u] = true; // 标记该地点为已访问
        
        for (int v = 1; v <= n; v++)// 更新与地点u相邻的地点的最短时间和距离
        {
            if (graph[u][v].dest != 0)
            {
                int newtime = tm[u] + graph[u][v].time;
                int newdist = dist[u] + graph[u][v].dst;
                if (newtime < tm[v] || (newtime == tm[v] && newdist < dist[v]))
                {
                    tm[v] = newtime;
                    dist[v] = newdist;
                    pre[v] = u;
                }
            }
        }
    }

    vector<int> path; // 构造路径
    int curr = d;
    while (curr != 1)
    {
        path.push_back(curr);
        curr = pre[curr];
    }
    path.push_back(1); // 加入起点

    // 输出结果
    cout << tm[d] << " " << dist[d] << " ";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i];
        if (i > 0)
            cout << "->";
    }
    cout << endl;
}

int main()
{
    cin >> n >> m >> d;

    for (int i = 0; i < m; i++)
    {
        int x, y, time, dist;
        cin >> x >> y >> time >> dist;
        graph[x][y] = {y, time, dist};
        graph[y][x] = {x, time, dist};
    }

    dijkstra();

    return 0;
}