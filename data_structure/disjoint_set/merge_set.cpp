#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int pre[N];

int find(int x)
{
    if (pre[x] != x)
        pre[x] = find(pre[x]); // 查找 + 路径压缩
    return pre[x];
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        pre[i] = i;

    while (m--)
    {
        char ope[2];
        int a, b;
        scanf("%s%d%d", ope, &a, &b);

        if (ope[0] == 'M')
            pre[find(a)] = find(b);
        else
        {
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
    }

    return 0;
}