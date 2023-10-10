#include <iostream>
using namespace std;

typedef long long LL;

int qmi(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1) // 判断b末尾数字是否是1
            res = (LL)res * a % p;
        b >>= 1;
        a = (LL)a * a % p; // 预处理a的值
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);

        printf("%d\n", qmi(a, b, p));
    }

    return 0;
}