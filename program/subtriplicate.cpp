#include <bits/stdc++.h>
#define ll long
using namespace std;

ll b[100000];

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= T; i++)
    {
        ll a = round(pow(b[i], 1.0 / 3));
        cout << a << endl;
    }
    return 0;
}