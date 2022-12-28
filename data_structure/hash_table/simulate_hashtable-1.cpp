// 拉链法
#include <iostream>
using namespace std;

const int N = 1e5 + 3;

int n;
int h[N], e[N], ne[N], idx = 1;

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx;
    idx++;
}

bool query(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i; i = ne[i])
        if (e[i] == x)
            return true;

    return false;
}

int main()
{
    cin >> n;

    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (op[0] == 'I')
            insert(x);
        else if (query(x))
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}