#include <bits/stdc++.h>
using namespace std;
int w[10005];
int dp[105][100005];
int m;
int main()
{
    int n;
    cin >> n;
    for (int k = 1; k <= n; k++)
    {
        scanf("%d", &w[k]);
        m += w[k];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j + w[i]] + dp[i - 1][abs(j - w[i])];
        }
    }
    int count = 0;
    for (int i = 1; i <= m; i++)
    {
        if (dp[n][i])
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}