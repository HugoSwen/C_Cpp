#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int pre[N], s[N];

int find(int x)
{
    if (pre[x] != x)
        pre[x] = find(pre[x]);
    return pre[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        pre[i] = i, s[i] = 1;

    while (m--)
    {
        char ope[3];
        int a, b;
        scanf("%s", ope);

        if (ope[0] == 'C')
        {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                continue;
            s[find(b)] += s[find(a)];
            pre[find(a)] = find(b);
        }
        else if (ope[1] == '1')
        {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
        else
        {
            scanf("%d", &a);
            printf("%d", s[find(a)]);
        }
    }

    return 0;
}