/*
 * Solution:开放寻址法
 */
#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e5 + 3, // 一般为数据范围2~3倍,且为质数,以此减少数据冲突
    null = 0x3f3f3f3f; // 空指针, 取0x3f3f3f3f一是方便初始化h, 二是没有爆int

int h[N];

int find(int x)
{
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x)
    {
        k++;
        if (k == N)
            k = 0;
    }

    return k;
}

int main()
{
    int n;
    cin >> n;

    memset(h, 0x3f, sizeof h);

    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        int k = find(x);
        if (op[0] == 'I')
            h[k] = x;
        else
        {
            if (h[k] != null)
                puts("Yes");
            else
                puts("No");
        }
    }

    return 0;
}