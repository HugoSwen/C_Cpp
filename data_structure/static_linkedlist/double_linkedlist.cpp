#include <iostream>
using namespace std;

const int N = 100010;

int e[N], l[N], r[N], idx;

// 双链表初始化
void init()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

// 在下标是k的点的右边插入x
void insert(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

// 删除下标是k的点
void del(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    int M;
    cin >> M;

    init();

    while (M--)
    {
        string ope;
        cin >> ope;

        int k, x;

        if (ope == "L")
        {
            scanf("%d", &x);
            insert(0, x);
        }
        else if (ope == "R")
        {
            scanf("%d", &x);
            insert(l[1], x);
        }
        else if (ope == "D")
        {
            scanf("%d", &k);
            del(k + 1);
        }
        else if (ope == "IL")
        {
            scanf("%d%d", &k, &x);
            insert(l[k + 1], x);
        }
        else if (ope == "IR")
        {
            scanf("%d%d", &k, &x);
            insert(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i])
        printf("%d ", e[i]);
    cout << endl;

    return 0;
}