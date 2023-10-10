#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10;

int n, a[N], backup[N];
LL cnt;

void merge_sort(int l, int r)
{
    if (l == r) return;
    
    int mid = l + r >> 1, i = l, j = mid + 1;
    merge_sort(l, j - 1), merge_sort(j, r);
    
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            backup[k++] = a[i++];
        else
        {
            cnt += mid - i + 1;
            backup[k++] = a[j++];
        }
    }
    
    while (i <= mid)
        backup[k++] = a[i++];
    while (j <= r)
        backup[k++] = a[j++];
    
    for (i = l; i <= r; i++) a[i] = backup[i - l];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    merge_sort(0, n - 1);
    
    cout << cnt << endl;
    return 0;
}