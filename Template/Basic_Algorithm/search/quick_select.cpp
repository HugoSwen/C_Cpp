#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int n, k;
int q[N];

int quick_select(int l, int r)
{
    if (l == r)
        return q[l];

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do
            i++;
        while (q[i] > x);
        do
            j--;
        while (q[j] < x);
        if (i < j)
            swap(q[i], q[j]);
    }
    // 快速选择
    // int sl = j - l + 1;
    // if (k <= j) // k<=sl说明第k个数在左半边
    //     return quick_select(l, j, k);
    // else // k > sl说明第k个数在右半边，且为右半边第k-sl个数
    //     return quick_select(j + 1, r, k);
    return quick_select(l, j);
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    cout << quick_select(0, n - 1);
    return 0;
}