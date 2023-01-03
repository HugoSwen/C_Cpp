#include <iostream>
using namespace std;

typedef long long LL;
const int N = 2e5 + 10;

int n;
LL a[N], s[N], ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        s[i] = s[i - 1] + a[i];
        ans += a[i] * s[i - 1];
    }

    cout << ans;

    return 0;
}