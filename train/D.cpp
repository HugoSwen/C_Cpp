#include <iostream>
using namespace std;

const int N = 205;

int T, n, m;
int g[N][N], q[N], tmp[N];
int cnt, cnt1, cnt2;

void merge_sort(int l, int r)
{
    if (l >= r)
        return;

    int mid = l + r >> 1;

    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
        {
            tmp[k++] = q[j++];
            cnt += (mid - i + 1);
        }

    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        int temp = (g[i][1] + m - 1) / m;
        for (int j = 2; j <= m; j++)
            if (temp != (g[i][j] + m - 1) / m)
                return true;
    }

    for (int j = 1; j <= m; j++)
    {
        int temp = (g[1][j] - 1) % m;
        for (int i = 2; i <= n; i++)
            if (temp != (g[i][j] - 1) % m)
                return true;
    }

    return false;
}

int main()
{
    cin >> T;
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &g[i][j]);

        if (check())
            puts("NSFW");
        else
        {
            for (int i = 1; i <= m; i++)
                q[i] = g[1][i];

            cnt = 0;
            merge_sort(1, m);
            cnt1 = cnt;

            for (int i = 1; i <= n; i++)
                    q[i] = g[i][1];
                
            cnt = 0;
            merge_sort(1, n);
            cnt2 = cnt;

            if (cnt1 == 1 && cnt2 == 0)
                puts("FOX");
            else if (n == 2 && m == 2)
            {
                if ((cnt1 + cnt2) & 1)
                    puts("FOX");
                else
                    puts("CAT");
            }
            else if (m == 2)
            {
                puts("FOX");
            }
            else if (n == 2)
            {
                puts("CAT");
            }
            else
                puts("NSFW");
        }
    }
    return 0;
}