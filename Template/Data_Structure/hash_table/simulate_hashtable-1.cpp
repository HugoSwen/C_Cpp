/*
 * solution:拉链法
 */
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 3; // 取大于1e5的第一个质数，取质数冲突的概率最小

int h[N], e[N], ne[N], idx; // 邻接表

void insert(int x)
{
    int k = (x % N + N) % N; // c++中如果是负数,那他取模也是负的,所以 +N再%N 就一定是一个正数
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx;
    idx++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;

    return false;
}

int main()
{
    int n;
    cin >> n;

    memset(h, -1, sizeof h); // 清空槽, 空指针一般用-1表示

    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (op[0] == 'I')
            insert(x);
        else
        {
            if (find(x))
                puts("Yes");
            else
                puts("No");
        }
    }

    return 0;
}