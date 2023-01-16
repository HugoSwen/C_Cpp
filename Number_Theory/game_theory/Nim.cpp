#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int res = 0;
    while (n--)
    {
        int c;
        scanf("%d", &c);
        res ^= c;
    }

    if (res) // 所有个数异或值不为0则先手必胜
        puts("Yes");
    else
        puts("No");

    return 0;
}