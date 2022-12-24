#include <iostream>
using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j]) // 当前待匹配值匹配到结果，子序列指针后移
            i++;
        j++; // 无论有没有匹配到,母序列指针都要后移
    }
    if (i == n)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}