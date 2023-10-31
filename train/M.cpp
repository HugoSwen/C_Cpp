#include <bits\stdc++.h>
using namespace std;

const int N = 1010, M = 1e6 + 10;
int n, m, k;
char s[M];
int U, D, L, R, u, d, l, r; // 代数坐标和矩阵坐标
bool st[N][N];
int f[N][N];

void add(int x1, int y1, int x2, int y2)
{
    f[x1][y1]++;
    f[x2 + 1][y1]--;
    f[x1][y2 + 1]--;
    f[x2 + 1][y2 + 1]++;
}
void solve()
{
    memset(f, 0, sizeof f);
    memset(st, 0, sizeof st);
    scanf("%d%d%d%s", &n, &m, &k, s);
    U = L = u = l = 1;
    R = r = m;
    D = d = n;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == 'D')
            u--, d--;
        else if (s[i] == 'U')
            u++, d++;
        else if (s[i] == 'L')
            r++, l++;
        else
            r--, l--;
        L = max(L, l);
        R = min(R, r);
        U = max(U, u);
        D = min(D, d);
    }
    // 没有袋鼠剩余
    if (L > R || U > D)
    {
        if (k)
            printf("0\n");
        else
            printf("%d\n", m * n);
        return;
    }

    // 剩余袋鼠数量
    int delta = (D - U + 1) * (R - L + 1) - k;
    if (delta < 0)
    {
        printf("0\n");
        return;
    }

    // 统计每个位置上经过了多少只不一样的袋鼠
    add(U, L, D, R);
    st[L][U] = 1;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == 'L')
            L--, R--;
        else if (s[i] == 'R')
            L++, R++;
        else if (s[i] == 'U')
            U--, D--;
        else
            U++, D++;
        if (st[L][U])
            continue;
        st[L][U] = 1;
        add(U, L, D, R);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (f[i][j] == delta)
                ans++;

    printf("%d\n", ans);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}