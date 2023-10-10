/*
 * 递推法O(nm)
 */
#include <iostream>
using namespace std;

const int P = 1e9 + 7, N = 2010;

int c[N][N];

int main()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (!j)
                c[i][j] = 1; // 每行首元素是1
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P; // 组合数的性质

    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", c[a][b]);
    }

    return 0;
}
