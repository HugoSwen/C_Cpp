#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, len;
int a[N], q[N];
// q[len] 记录长度为len的上升子序列末尾最小的数

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
    {
        int l = 0, r = len; // 二分范围 0~len
        while (l < r)       // 找到小于a[i] 的最大的q[l]
        {
            int mid = l + r + 1 >> 1;
            if (q[mid] >= a[i])
                r = mid - 1;
            else
                l = mid;
        }
        q[l + 1] = a[i];       // 将a[i]接在q[l]后面更新长度为 l + 1 的上升子序列末尾的最小值
        len = max(len, l + 1); // 判断是否产生更长的序列
    }

    cout << len << endl;
    return 0;
}