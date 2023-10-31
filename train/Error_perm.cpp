#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 5005;

int T, n;
int a[N];
int s[N][N];

int main()
{
    cin >> T;
    while (T --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                s[i][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            int cnt = 0, rl = i, rr = i + 1;
            for (int l = i; l >= 1; l--)
            {
                if (a[l] < a[i]) cnt++;
                while (rr <= n && cnt < i - l)
                {
                    if (a[rr] < a[i]) cnt++;
                    rl = rr; // 记录最先满足的点
                    rr++;
                }

                if (cnt == i - l)
                {
                    while (rr <= n && a[rr] > a[i]) rr++;
                    s[l][rl]++;
                    s[l][rr]--;
                }
            }
        }

        int res = n * (n + 1) / 2;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                s[i][j] += s[i][j - 1];
                res -= s[i][j] ? 1 : 0;
            }
        
        cout << res << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 5005;

// int n;
// int p[N];
// int f[N][N];

// void solve()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> p[i];
//     for (int i = 1; i <= n + 1; i++)
//         for (int j = 1; j <= n + 1; j++)
//             f[i][j] = 0;

//     auto add = [&](int x1, int y1, int x2, int y2) -> void
//     {
//         f[x1][y1] += 1, f[x1][y2 + 1] -= 1;
//         f[x2 + 1][y1] -= 1, f[x2 + 1][y2 + 1] += 1;
//     };

//     for (int i = 1; i <= n; i++)
//     {
//         int j = i, k = i;
//         while (j >= 1 && k <= n)
//         {
//             int pr = j, su = k;
//             while (pr - 1 >= 1 && p[pr - 1] < p[i])
//                 pr -= 1;
//             while (su + 1 <= n && p[su + 1] > p[i])
//                 su += 1;
//             add(pr, k, j, su);
//             j = pr - 1, k = su + 1;
//         }
//     }

//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++)
//             f[i][j] = f[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];

//     int ans = 0;
//     for (int i = 1; i <= n; i++)
//         for (int j = i; j <= n; j++)
//             ans += (f[i][j] == 0);

//     cout << ans << '\n';
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int T;
//     cin >> T;
//     while (T--)
//         solve();
//     return 0;
// }