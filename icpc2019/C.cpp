#include <bits\stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, k, a[N], st[4 * N];
unordered_map<int, int> mp;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (!mp[a[i]])
            st[a[i] + 2 * N] = i;

        mp[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i > st[a[i] + 2 * N]) continue;

        int num = a[i], cnt = mp[num];
        // cout << num << " " << cnt << endl;
        if (cnt + mp[num - k] > ans)
        {   
            int flag = 0, maxv = 0;
            if (st[num - k + 2 * N])
                for (int j = st[num - k + 2 * N]; j <= n; j++)
                {
                    if (k && a[j] == num - k)
                        flag++, maxv = max(flag, maxv);
                    else if (a[j] == num)
                        flag--, flag = max(flag, 0);
                }
                    
            ans = max(ans, cnt + maxv);
        }
    }
    cout << ans << endl;
    return 0;
}