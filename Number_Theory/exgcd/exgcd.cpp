#include <iostream>
using namespace std;

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0) // 边界条件
    {
        x = 1, y = 0;
        return a;
    }

    int d = exgcd(b, a % b, y, x); // 交换x y的位置便于计算
    y -= a / b * x;                // ax + b(y - a/b * x) = gcd(a, b)
    return d;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, x, y;
        scanf("%d%d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }

    return 0;
}