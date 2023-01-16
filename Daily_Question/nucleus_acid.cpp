/*
差分差分差分！！！
*/
#include <iostream>
using namespace std;

const int N = 2e5 + 10;

int n, m, k;
int cnt[N]; // 统计每个位置在几个区间内

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        int t, c;
        scanf("%d%d", &t, &c);
        cnt[max(1, t - k - c + 1)]++;
        cnt[max(1, t - k + 1)]--;
    }

    for (int i = 1; i <= N; i++)
        cnt[i] += cnt[i - 1];

    while (m--)
    {
        int q;
        scanf("%d", &q);
        printf("%d\n", cnt[q]);
    }

    return 0;
}