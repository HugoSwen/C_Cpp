#include <iostream>
using namespace std;

const int N = 100010;

int n, a[N], cns[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        cns[a[i]]++;
        while (cns[a[i]] > 1)
        {
            cns[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    printf("%d", res);
    return 0;
}