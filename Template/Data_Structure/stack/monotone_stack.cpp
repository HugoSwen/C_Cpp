#include <iostream>
using namespace std;

const int N = 100010;

int n;
int stk[N], st;

int main()
{
    scanf("%d", &n);

    while (n--)
    {
        int x;
        scanf("%d", &x);

        while (st && stk[st] >= x) // 找到单调栈中小于x的最大的数
            st--;                  // 同时删除了不可能作为答案的尾部

        if (st) // st非零说明找到结果
            printf("%d ", stk[st]);
        else // st为零说明不存在
            cout << -1 << " ";

        stk[++st] = x; // 添加新栈顶
    }

    return 0;
}