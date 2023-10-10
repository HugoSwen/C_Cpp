/*
排序不等式证明
*/
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;

int n;
int t[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &t[i]);

    sort(t + 1, t + n + 1);

    LL res = 0;
    for (int i = 1; i <= n; i++)
        res += t[i] * (n - i);

    cout << res << endl;
    return 0;
}