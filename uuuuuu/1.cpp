#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define all(x) (x).begin(), (x).end()
#define show(x)                \
    {                          \
        for (auto it : x)      \
            cout << it << " "; \
        cout << endl;          \
    }
typedef long long ll;
typedef unsigned long long ull;

const ull P = 10007;
ull PP[5005], _ = []
{
    PP[0] = 1;
    for (int i = 1; i <= 5004; i++)
        PP[i] = PP[i - 1] * P;
    return 0;
}();

vector<ull> get_has(string &s)
{
    ull h = 0;
    vector<ull> has;
    for (char c : s)
    {
        has.push_back(h = h * P + c * 3);
    }
    return has;
}

ull get_h(auto &v, int l, int r)
{
    if (l == 0)
        return v[r];
    else
        return v[r] - v[l - 1] * PP[r - l + 1];
}

void sol()
{
    string s;
    cin >> s;

    auto has = get_has(s);

    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int nl = i + 1, nr = i;
        for (int l = i, r = i + 1; l >= 0 && r < s.size(); l--, r++)
        {
            if (get_h(has, l, nl - 1) == get_h(has, nr + 1, r))
                ans++, nl = l, nr = r;
        }
    }

    cout << ans << endl;
}

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\code1\\zz.in", "r", stdin);
    freopen("C:\\Users\\Administrator\\Desktop\\code1\\zz.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        sol();
    }
}