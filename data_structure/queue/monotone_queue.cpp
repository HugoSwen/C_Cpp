#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int a[N], que[N];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int qh = 1, qt = 0;
    for (int i = 0; i < n; i++)
    {

        if (qh <= qt && i - k + 1 > que[qh])
            qh++;
        while (qh <= qt && a[que[qt]] >= a[i])
            qt--;
        que[++qt] = i;
        if (i >= k - 1)
            printf("%d ", a[que[qh]]);
    }
    cout << endl;

    qh = 1, qt = 0;
    for (int i = 0; i < n; i++)
    {

        if (qh <= qt && i - k + 1 > que[qh])
            qh++;
        while (qh <= qt && a[que[qt]] <= a[i])
            qt--;
        que[++qt] = i;
        if (i >= k - 1)
            printf("%d ", a[que[qh]]);
    }
    cout << endl;

    return 0;
}
