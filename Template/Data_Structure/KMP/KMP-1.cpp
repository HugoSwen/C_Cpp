#include <iostream>
using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
char p[N], s[M];
int ne[N]; // 存储当前位置前面的最大公共前后缀长度 + 1 (规定ne[1] = 0)

int main()
{
    scanf("%d%s%d%s", &n, p + 1, &m, s + 1);

    for (int i = 2, j = 0; i <= n + 1; i++)
    {
        while (j && p[i - 1] != p[j])
            j = ne[j];
        ne[i] = ++j;
    }

    for (int i = 1, j = 1; i <= m; i++)
    {
        while (j && s[i] != p[j])
            j = ne[j];
        j++;
        if (j == n + 1)
        {
            printf("%d ", i - n);
            j = ne[j];
        }
    }

    return 0;
}