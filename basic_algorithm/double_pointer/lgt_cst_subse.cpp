#include <iostream>
using namespace std;

const int N = 100010;

int n, a[N], cns[N]; // cns记录对应数字出现次数

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        cns[a[i]]++;          // i指针当前所在位置数字的次数+1
        while (cns[a[i]] > 1) // i当前所在位置数字重复
        {
            cns[a[j]]--; // j指针当前所在位置数字的次数-1
            j++;         // j指针前移
        }
        res = max(res, i - j + 1); // i-j+1即为当前无重复连续子序列的长度
    }
    printf("%d", res);
    return 0;
}