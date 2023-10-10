#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1e6 + 10;

int T, n, k;
int b[N], a[35];

int main()
{
    cin >> T;
    while (T--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i < n; i++)
            scanf("%d", &b[i]), b[i] ^= b[i - 1];

        memset(a, -1, sizeof a);

        bool flag = true;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 29; j >= 0; j--)
            {
                int x = (b[i] >> j) & 1, y = (b[i + 1] >> j) & 1;
                if (x == 0 && y == 1)
                {
                    if (a[j] == 1)
                        flag = false;
                    else
                        a[j] = 0;
                    break;
                }
                else if (x == 1 && y == 0)
                {
                    if (a[j] == 0)
                        flag = false;
                    else
                        a[j] = 1;
                    break;
                }
            }
        }

        int cnt = 0;
        for (int i = 29; i >= 0; i--)
            if (a[i] == -1)
                cnt++;

        if (!flag || pow(2, cnt) < k)
            puts("-1");
        else
        {
            k--;
            int res = 0;
            for (int i = 0; i <= 29; i++)
            {
                if (a[i] == -1)
                    a[i] = k % 2, k >>= 1;
                res += a[i] << i;
            }

            for (int i = 0; i < n; i++)
                printf("%d ", res ^ b[i]);
            printf("\n");
        }
    }
    return 0;
}