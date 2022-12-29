#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, sp[N];

bool check(int smul) // 判断每堆数量为smul时是否符合条件
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += sp[i];
        if (s == smul) // 当前合并位置符合条件
            s = 0;
        if (s > smul) // 不符合条件
            return false;
    }

    return true;
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int sum = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &sp[i]);
            sum += sp[i]; // 累计总石子数
        }

        for (int i = n; i >= 1; i--) // 堆数从n开始枚举,堆数越多操作次数越少
        {
            if (sum % i == 0 && check(sum / i)) // 当i为sum的约数,并且经check判断符合条件
            {
                printf("%d\n", n - i);
                break;
            }
        }
    }

    return 0;
}