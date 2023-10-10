#include <bits/stdc++.h>
#define dbg() cout<<"-------"
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const int p = 998244353;
int n, a[N];
ll ans;
int backup[N];

void merge_sort(int l, int r)
{
    if (l == r) return;
    
    int mid = l + r >> 1, i = l, j = mid + 1;
    merge_sort(l, j - 1), merge_sort(j, r);
    
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            backup[k++] = a[i++];
        else
        {
            ans += mid - i + 1;
            backup[k++] = a[j++];
        }
    }
    
    while (i <= mid)
        backup[k++] = a[i++];
    while (j <= r)
        backup[k++] = a[j++];
    
    for (i = l; i <= r; i++) a[i] = backup[i - l];
}

void solve() {
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    merge_sort(1, n);
    if (ans & 1) {
        cout << 2 << ' ';
        ll temp = (ll)n * (n - 1) / 2 - ans;
        if (temp & 1) {
            ll temp2 = 2 ^ n;
            temp2 >>= 1;
            temp2 <<= 1;
            temp2++;
            cout << temp2 << endl;
        }
        else {
            ll temp2 = n;
            temp2 >>= 1;
            temp2 <<= 1;
            temp2++;
            cout << temp2 << endl;
        }
    }
    else {
        cout << 0 << ' ';
        ll temp = (ll)n * (n - 1) / 2 - ans;
        if (temp & 1) {
            ll temp2 = 2 ^ n;
            temp2 >>= 1;
            temp2 <<= 1;
            temp2++;
            cout << temp2 << endl;
        }
        else {
            ll temp2 = n;
            temp2 >>= 1;
            temp2 <<= 1;
            temp2++;
            cout << temp2 << endl;
        }
    }

}
int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    //  t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

