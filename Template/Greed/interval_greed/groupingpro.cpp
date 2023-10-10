/*
手写堆版
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int n;
int heap[N], s;

struct Range
{
    int l, r;
    bool operator<(const Range &w) const
    {
        return l < w.l;
    }
} range[N];

void up(int x)
{
    while (x > 1 && heap[x] < heap[x / 2])
        swap(heap[x], heap[x / 2]), x /= 2;
}

void down(int x)
{
    int p = x;
    if (2 * x <= s && heap[2 * x] < heap[p])
        p = 2 * x;
    if (2 * x + 1 <= s && heap[2 * x + 1] < heap[p])
        p = 2 * x + 1;
    if (p != x)
    {
        swap(heap[p], heap[x]);
        down(p);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);

    for (int i = 0; i < n; i++)
    {
        auto r = range[i];
        if (!s || r.l <= heap[1])
            heap[++s] = r.r, up(s);
        else
            heap[1] = r.r, down(1);
    }

    cout << s << endl;
    return 0;
}