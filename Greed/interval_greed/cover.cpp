#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int s, t;
int n;

struct Range
{
    int l, r;
    bool operator<(const Range &w) const
    {
        return l < w.l;
    }
} range[N];

int main()
{
    cin >> s >> t >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);

    int res = 0;
    bool success = false;
    for (int i = 0; i < n; i++)
    {
        int j = i, r = -2e9;
        while (j < n && range[j].l <= s)
            r = max(r, range[j].r), j++;

        if (r < s)
            break;

        res++;
        if (r >= t)
        {
            success = true;
            break;
        }

        s = r;
        i = j - 1;
    }

    if (!success)
        res = -1;
    cout << res << endl;
    return 0;
}