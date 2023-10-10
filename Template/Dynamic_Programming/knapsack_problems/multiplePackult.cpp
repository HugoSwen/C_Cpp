#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010, M = 2e4 + 10;

int n, m;
int v, w, s;
int q[M], qh, qt;
int f[M], g[M];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &v, &w, &s);
        memcpy(g, f, sizeof g);
        for (int r = 0; r < v; r++)
        {
            qh = 0, qt = -1;
            for (int j = r; j <= m; j += v)
            {
                if (qh <= qt && j - q[qh] > s * v)
                    qh++;
                while (qh <= qt && g[q[qt]] + (j - q[qt]) / v * w <= g[j])
                    qt--;
                q[++qt] = j;
                f[j] = g[q[qh]] + (j - q[qh]) / v * w;
            }
        }
    }

    cout << f[m] << endl;
    return 0;
}