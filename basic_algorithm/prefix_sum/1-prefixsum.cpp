#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], s[N];

int main()
{
    // ios::sync_with_stdio(false); // 取消同步，提高输入输出速度，但仍比scanf printf慢
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];

    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}