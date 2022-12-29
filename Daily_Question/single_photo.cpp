#include <iostream>
#define ll long long
using namespace std;

const int N = 5e5 + 10;

int n;
char str[N];
ll ans;

int main()
{
    scanf("%d%s", &n, str);

    int L, R;
    for (int i = 0; i < n; i++)
    {
        L = R = 0;
        for (int f = i - 1; f >= 0; f--) // 统计i位置左边连续的与i位置不同的字母
        {
            if (str[f] != str[i])
                L++;
            else
                break;
        }
        for (int r = i + 1; r < n; r++) // 统计i位置右边连续的与i位置不同的字母
        {
            if (str[r] != str[i])
                R++;
            else
                break;
        }

        ans += (ll)L * R + max(L - 1, 0) + max(R - 1, 0); // 排列组合计算总数
    }
    cout << ans << endl;
    return 0;
}