#include <iostream>
using namespace std;

const int N = 100010;

int stk[N], st = 0;

void push(int x)
{
    stk[++st] = x;
}

void pop()
{
    st--;
}

bool empty()
{
    return st <= 0;
}

int query()
{

    return stk[st];
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