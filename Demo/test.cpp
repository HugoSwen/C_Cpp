#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n, k;
int a[N];
int q[N], qh = 0, qt = -1;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    cin >> k;

    for (int i = 1, r = 1; i <= n; i++)
    {
        if (q[qh] < i - k)
            qh++;
        while (r <= i + k && r <= n)
        {
            while (qh <= qt && a[q[qt]] >= a[r])
                qt--;
            q[++qt] = r++;
        }
        printf("%d ", a[q[qh]]);
    }
    return 0;
}