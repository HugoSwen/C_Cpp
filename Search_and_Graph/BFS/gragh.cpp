#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], e[N], ne[N], idx, d[N];
queue<int> q; // 宽搜的容器

void add(int a, int b) // 有向边的插入
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs()
{
    d[1] = 0;  // 出发点距离自身为0
    q.push(1); // 出发点push队列，为宽搜的起点

    while (!q.empty()) // 当队列不为空时，即无法再进行扩展
    {
        int u = q.front(); // 取队首元素, 即待扩展的节点
        q.pop();

        for (int i = h[u]; i != -1; i = ne[i]) // 遍历所以可以扩展到的节点
        {
            int j = e[i];
            if (d[j] == -1) // 节点未被搜索过
            {
                d[j] = d[i] + 1; // 扩展点到出发点的距离
                q.push(j);       // 将扩展点push队列，待进一步扩展
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);
    memset(d, -1, sizeof d);

    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    bfs();
    cout << d[n];

    return 0;
}