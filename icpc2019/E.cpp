#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, a, b, x, y;
    cin >> n >> a >> b;

    if (a - 1 < n - a)
    {
        x = 1;
        for (int i = 1; i < n; i++)
            printf("U");
    }
    else
    {
        x = n;
        for (int i = 1; i < n; i++)
            printf("D");
    }

    if (b - 1 < n - b)
    {
        y = 1;
        for (int i = 1; i < n; i++)
            printf("L");
    }
    else
    {
        y = n;
        for (int i = 1; i < n; i++)
            printf("R");
    }

    int dx = a - x, dy = b - y;
    if (dx < 0)
        for (int i = 1; i <= abs(dx); i++)
            printf("U");
    else
        for (int i = 1; i <= abs(dx); i++)
            printf("D");

    if (dy < 0)
        for (int i = 1; i <= abs(dy); i++)
            printf("L");
    else
        for (int i = 1; i <= abs(dy); i++)
            printf("R");
    printf("\n");
    return 0;
}
