#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
typedef long long ll;
int a[N], n, sum;

void solve()
{
    scanf("%d", &n);
    sum = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    int cnt = 1, attack = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            cnt++, attack++;
        else if (a[i] == -1)
        {
            if (cnt > 1)
                cnt--;
            else if (sum >= 1)
                sum--, attack++, cnt++;
            else
            {
                printf("-1\n");
                return;
            }
        }
        else
        {
            if (cnt > 1)
                cnt--, sum++;
            else
                cnt++, attack++;
        }
    }

    printf("%d %d\n", attack / __gcd(attack, cnt), cnt / __gcd(attack, cnt));
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        solve();
    }
    return 0;
}