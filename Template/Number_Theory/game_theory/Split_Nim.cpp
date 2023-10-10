#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 110;

int SG[N];

int sg(int x)
{
    if (SG[x] != -1)
        return SG[x];

    // 找到所有可达到的状态的sg函数值
    unordered_set<int> ac;
    for (int i = 0; i < x; i++)
        for (int j = 0; j <= i; j++)
            ac.insert(sg(i) ^ sg(j)); // 相当于一个局面拆分成了两个局面，由SG函数理论，多个独立局面的SG值，等于这些局面SG值的异或和

    // mex操作
    for (int i = 0;; i++)
        if (!ac.count(i))
            return SG[x] = i;
}

int main()
{
    int n;
    cin >> n;

    memset(SG, -1, sizeof SG);

    int res = 0;
    while (n--)
    {
        int x;
        cin >> x;
        res ^= sg(x);
    }

    if (res)
        puts("Yes");
    else
        puts("No");

    return 0;
}