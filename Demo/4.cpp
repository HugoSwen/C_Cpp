#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

const int N = 1005, M = 10005;

struct node2
{
    int t;
    int d;
    int num;
    int t_node;
    int d_node;
    int t_d_node;
    int path[N];
} date[M];

struct node
{
    int from;
    int to;
    int t;
    int d;
    int next;
} edge[M];

int head[N];
int number = 0;
int n, m, f;
bool book[N];
int path_num = 1;
int date_path[M];
int mint = 9999;
int mind = 9999;

bool cmp_d(const node2 a, const node2 b)
{
    return a.d < b.d;
}
bool cmp_t(const node2 a, const node2 b)
{
    return a.t < b.t;
}
bool cmp_t_d(const node2 a, const node2 b)
{
    return a.t_d_node < b.t_d_node;
}
void add(int from, int to, int t, int d)
{
    edge[++number].next = head[from];
    edge[number].from = from;
    edge[number].to = to;
    edge[number].t = t;
    edge[number].d = d;
    head[from] = number;
}
void dfs(int k, int step, int sum_t, int sum_d)
{
    if (k == f)
    {
        mint = min(sum_t, mint);
        mind = min(sum_d, mind);
        date[path_num].d = sum_d;
        date[path_num].t = sum_t;
        date[path_num].num = path_num;
        for (int i = 0; i <= step; i++)
            date[path_num].path[i] = date_path[i];
        path_num++;
        return;
    }

    if (sum_t > mint * 2 && sum_d > mind * 2)
        return;

    /*if(path_num>7000)
        return;*/

    for (int j = head[k]; j; j = edge[j].next)
    {
        if (!book[k])
        {
            book[k] = true;
            // date[path_num].path[step] = edge[j].to;
            date_path[step] = edge[j].to;
            dfs(edge[j].to, step + 1, sum_t + edge[j].t, sum_d + edge[j].d);
            book[k] = false;
        }
    }
}

void print_ans()
{

    cout << date[1].t << " " << date[1].d << " ";
    cout << "1"
         << "->";
    for (int j = 1; date[1].path[j]; j++)
    {
        cout << date[1].path[j];
        if (date[1].path[j + 1])
            cout << "->";
    }
}
int main()
{
    int x, y, t, d;

    cin >> n >> m >> f;

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d%d", &x, &y, &t, &d);
        add(x, y, t, d);
        add(y, x, t, d);
    }
    date_path[0] = 1;
    dfs(1, 1, 0, 0);
    sort(date + 1, date + 1 + path_num - 1, cmp_t);
    for (int k = 1; k <= path_num - 1; k++)
    {
        date[k].t_node = k;
    }
    sort(date + 1, date + 1 + path_num - 1, cmp_d);
    for (int k = 1; k <= path_num - 1; k++)
    {
        date[k].d_node = k;
        date[k].t_d_node = date[k].t_node + date[k].d_node;
    }
    sort(date + 1, date + 1 + path_num - 1, cmp_t_d);

    // print();
    print_ans();

    return 0;
}
