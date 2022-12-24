#include <iostream>
using namespace std;

int lowbit(int x)
{
    return x & -x; // 得到x二进制数最后一位1表示的数
}

int n;

int main()
{
    cin >> n;

    while (n--)
    {
        int x;
        scanf("%d", &x);

        int res = 0;
        while (x)
            x -= lowbit(x), res++;
        cout << res << " ";
    }
    return 0;
}