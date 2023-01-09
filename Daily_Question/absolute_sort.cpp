/*
 * 思维较难
 */
#include <iostream>
using namespace std;

const int N = 2e5 + 10;
int a[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int top = 1e9, base = 0; // 上界，下界
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            int temp = (a[i] + a[i + 1]) / 2; // 向下取整求满足abs(a[i]-x)<=abs(a[i+1]-x)的最高位置
            top = min(top, temp);             // 更新x能取的上界
        }
        else if (a[i] > a[i + 1])
        {
            int temp = (a[i] + a[i + 1] + 1) / 2; // 向上取整求满足abs(a[i]-x)<=abs(a[i+1]-x)的最低位置
            base = max(base, temp);               // 更新x能取的下界
        }
    }
    if (base > top)
        cout << -1 << endl; // 下界超过上界无法找到x
    else
        cout << base << endl; // 输出下界到上界任意值
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}