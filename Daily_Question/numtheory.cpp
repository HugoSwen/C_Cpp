/*
 * 较难 待复盘
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
int n;
ll a[N];
int c[N];
void work()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++)
        if (a[i] == a[i - 1])
        {
            puts("No");
            return;
        }
    for (int i = 2; i <= n / 2; i++)
    {
        for (int j = 0; j < i; j++)
            c[j] = 0;
        for (int j = 1; j <= n; j++)
            c[a[j] % i]++;
        bool p = 0;
        for (int j = 0; j < i; j++)
            if (c[j] < 2)
                p = 1;
        if (!p)
        {
            puts("No");
            return;
        }
    }
    puts("Yes");
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        work();
    return 0;
}