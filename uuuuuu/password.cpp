#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MOD = 998244353, N = 1e5 + 10;

int n;
char str[N];
ll f[2][62][8], s[2][8];
int mp[128];

inline int get_bit(char c)
{
    if (c >= '0' && c <= '9')
        return 4;
    else if (c >= 'A' && c <= 'Z')
        return 2;
    else if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

void cal(char c, int i)
{
    int pre = (i - 1) & 1, now = i & 1;
    for (int k = 0; k <= 7; k++)
    {
        int sk = get_bit(c) | k; // 标志 状态 或运算

        f[now][mp[c]][sk] = ((f[now][mp[c]][sk] + s[pre][k] - f[pre][mp[c]][k]) % MOD + MOD) % MOD;
        s[now][sk] = ((s[now][sk] + s[pre][k] - f[pre][mp[c]][k]) % MOD + MOD) % MOD;
    }
}

int main()
{
    cin >> n;
    scanf("%s", str + 1);

    char i;
    int j = 0;
    for (i = '0'; i <= '9'; i++, j++)
        mp[i] = j;
    for (i = 'A'; i <= 'Z'; i++, j++)
        mp[i] = j;
    for (i = 'a'; i <= 'z'; i++, j++)
        mp[i] = j;

    s[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        char c = str[i];

        memset(f[i & 1], 0, sizeof f[i & 1]);
        memset(s[i & 1], 0, sizeof s[i & 1]);

        if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z')
            cal(c, i);
        else if (c >= 'a' && c <= 'z')
        {
            int t = 2;
            while (t--)
            {
                cal(c, i);
                c -= 32;
            }
        }
        else if (c == '?')
        {
            for (c = '0'; c <= '9'; c++)
                cal(c, i);
            for (c = 'A'; c <= 'Z'; c++)
                cal(c, i);
            for (c = 'a'; c <= 'z'; c++)
                cal(c, i);
        }
    }

    cout << s[n & 1][7] << endl;
    return 0;
}