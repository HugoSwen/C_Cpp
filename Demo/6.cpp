#include <iostream>
#include <cstring>
using namespace std;

const int N = 100005;

int n, k, f[N], m[N], x, fa, mo; // 总人数 总情侣数 每个ID的父亲 每个ID的母亲 本人ID 父亲ID 母亲ID
int a, b;                        // 输入的情侣的ID
char gen, gender[N];             // 记录每个ID的性别
bool flag, st[N];                // 判断每个祖先是否被遍历过

void dfs(int u, int t)
{
    if (t > 5) // 超过五代停止遍历
        return;
    if (st[u]) // 判断该祖先是否被遍历过
    {
        flag = false; // 置标记为否
        return;
    }
    st[u] = true;   // 标记已经遍历过
    if (f[u] != -1) // 父亲不为空递归遍历
        dfs(f[u], t + 1);

    if (m[u] != -1) // 母亲不为空递归遍历
        dfs(m[u], t + 1);
}
int main()
{
    cin >> n;
    memset(f, -1, sizeof f); // 初始化父亲数组
    memset(m, -1, sizeof m); // 初始化母亲数组
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> gen >> fa >> mo;
        f[x] = fa;
        m[x] = mo;
        gender[x] = gen;
        gender[fa] = 'M';
        gender[mo] = 'F';
    }

    cin >> k;
    while (k--)
    {
        scanf("%d%d", &a, &b);
        if (gender[a] == gender[b])
            cout << "Never Mind" << endl;
        else
        {
            flag = true;
            memset(st, false, sizeof st); // 清空标记数组
            dfs(a, 1);
            dfs(b, 1);
            if (flag) // 最近公共祖先不在五代以内
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
