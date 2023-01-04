#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);

        int group = n / 2;
        for (int i = 1, t = n; i <= group; i++)
        {
            printf("%d %d ", t, n + 1 - t);
            t--;
        }

        if (n % 2 == 1)
            printf("%d\n", (n + 1) / 2);
        else
            printf("\n");
    }

    return 0;
}