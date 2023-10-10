#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (i % 2) // 只考虑奇数级台阶
            res ^= x;
    }

    if (res)
        puts("Yes");
    else
        puts("No");

    return 0;
}