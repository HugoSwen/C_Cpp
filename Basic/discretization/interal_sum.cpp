#include <iostream>
#include <vector>
#include <algorithm>
#define PII pair<int, int> // 有序对

using namespace std;

const int N = 300010;

int n, m;
int a[N], s[N];

vector<int> alls;           // 离散化数组
vector<PII> operate, query; // 操作  询问

int find(int x, vector<int> &alls)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }

    return l + 1;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int x, c;
        scanf("%d%d", &x, &c);
        operate.push_back({x, c});

        alls.push_back(x);
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        query.push_back({l, r});

        alls.push_back(l);
        alls.push_back(r);
    }

    // 去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 处理操作
    for (auto ope : operate)
    {
        int x = find(ope.first,alls);
        a[x] += ope.second;
    }

    // 预处理前缀和
    for (int i = 1; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];

    // 处理询问
    for (auto que : query)
    {
        int l = find(que.first,alls),
            r = find(que.second,alls);

        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}