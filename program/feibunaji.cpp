#include <iostream>
using namespace std;
#define ll long long
ll f[100005];
int t[1005];

int main()
{
    int T, A, B;
    cin >> T >> A >> B;
    for (int i = 1; i <= T; i++)
    {
        cin >> t[i];
    }
    f[1] = f[2] = 1;
    for (int n = 3; n <= 100000; n++)
    {
        f[n] = A * f[n - 1] + B * f[n - 2];
        
    }
    for (int i = 1; i <= T; i++)
    {
        cout << f[t[i]] % 1000000007 << endl;
    }
    return 0;
}