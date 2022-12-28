#include <iostream>
using namespace std;

const int N = 100010;

// head 表示头节点下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针
// idx 表示当前用到了哪个节点
int head, e[N], ne[N], idx;

// 初始化
void init()
{
    head = -1;
    idx = 0;
}

// 将x插到头节点
void insert_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

// 将下标是k的点后边的点删掉
void del(int k)
{
    ne[k] = ne[ne[k]];
}

// 将x插到下标是k的点的后面
void insert(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

int main()
{
    int M;
    cin >> M;

    init();

    while (M--)
    {
        int k, x;
        char ope;
        cin >> ope;

        if (ope == 'H')
        {
            scanf("%d", &x);

            insert_to_head(x);
        }
        else if (ope == 'D')
        {
            scanf("%d", &k);

            if (!k)
                head = ne[head];
            else
                del(k - 1);
        }
        else
        {
            scanf("%d%d", &k, &x);

            insert(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i])
        printf("%d ", e[i]);

    cout << endl;

    return 0;
}