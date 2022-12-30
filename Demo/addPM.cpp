#include <iostream>
using namespace std;

const int N = 105;

int t, n;
char a[N];

int main()
{
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d%s", &n, a);

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1')
                cnt++;
            if (cnt == 2)
            {
                printf("-");
                cnt = 0;
            }
            else if (i)
                printf("+");
        }
        puts("");
    }

    return 0;
}