#include <iostream>
using namespace std;

const int N = 1e5 + 10, M = 3.1e6 + 10;

int a[N], son[M][2], idx;

// 建Trie树
void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--) // i >= 0 可写成 ~i,因为当i == -1时 ~i == 0;
    {
        int &s = son[p][x >> i & 1]; // x >> i & 1 取x的第i位的二进制数
        if (!s)                      // 这里使用引用绑定s和son[p][x >> i & 1],省代码
            s = ++idx;
        p = s;
    }
}

// 找到x在Trie树中取异或最大的那条路
// 每一次检索的时候,我们都走与当前xi这一位相反的位置走,也就是让Xor值最大,如果说没有路可以走的话,那么就走相同的路.
int find(int x)
{
    int res = 0, p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int s = x >> i & 1;
        if (son[p][!s])
        {
            res += 1 << i; // 1 << i 是该位1的贡献
            p = son[p][!s];
        }
        else
            p = son[p][s];
    }

    return res;
}

int main()
{
    int n, res = 0;
    ;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        insert(a[i]);
        res = max(res, find(a[i]));
    }

    printf("%d", res);

    return 0;
}