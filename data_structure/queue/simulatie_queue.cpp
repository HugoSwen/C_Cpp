#include <iostream>
using namespace std;

const int N = 100010;

int que[N], qh = 1, qt = 0;

void push(int x)
{
    que[++qt] = x;
}

void pop()
{
    qh++;
}

bool empty()
{
    return qh > qt;
}

int query()
{
    return que[qh]; // 队首元素
}

int queryt()
{
    return que[qt]; // 队尾元素
}

int main()
{
    int M;
    cin >> M;

    int x;

    while (M--)
    {
        string ope;
        cin >> ope;

        if (ope == "push")
        {
            scanf("%d", &x);
            push(x);
        }
        else if (ope == "pop")
            pop();
        else if (ope == "empty")
        {
            if (empty())
                printf("YES\n");
            else
                printf("NO\n");
        }
        else if (ope == "query")
            printf("%d\n", query());
    }

    return 0;
}