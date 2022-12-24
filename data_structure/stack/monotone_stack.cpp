#include <iostream>
using namespace std;

const int N = 100010;

int n;
int stk[N], tt;

int main()
{
    scanf("%d", &n);

    while (n--)
    {
        int x;
        scanf("%d", &x);

        while (tt && stk[tt] >= x) // 找到单调栈中小于x的最大的数
            tt--;
        if (tt) // tt非零说明找到结果
            printf("%d ", stk[tt]);
        else // tt为零说明不存在
            cout << -1 << " ";
        // 同时删除了不可能作为答案的尾部

        stk[++tt] = x; // 添加新栈顶
    }

    return 0;
}