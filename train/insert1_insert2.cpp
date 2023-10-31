#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
int n, a;
ll ans;
vector<int> st[N], va;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);

        if (a == 1)
        {
            st[1].push_back(i);
            va.push_back(i);
        }
        else
        {
            int r = 0;
            if (!st[a - 1].empty())
            {
                r = st[a - 1].back();
                st[a - 1].pop_back();
                st[a].push_back(r);
            }
            while (!va.empty() && va.back() > r)
                va.pop_back();
        }

        ans += va.size();
    }

    cout << ans << endl;
    return 0;
}
