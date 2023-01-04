/*
 * 第m个数，快速选择算法
 */
#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int a[N], s[N];

int get_sum(int x)
{
    int sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

bool cmp(int a, int b)
{
    if (s[a] != s[b])
        return s[a] < s[b];
    return a < b;
}

int quick_select(int l, int r, int k)
{
    if (l == r)
        return a[l];

    int i = l - 1, j = r + 1, x = a[l + r >> 1];
    while (i < j)
    {
        do
            i++;
        while (cmp(a[i], x));
        do
            j--;
        while (cmp(x, a[j]));
        if (i < j)
            swap(a[i], a[j]);
    }
    if (k <= j)
        return quick_select(l, j, k);
    return quick_select(j + 1, r, k);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        s[i] = get_sum(i);
    }

    cout << quick_select(1, n, m);
    return 0;
}