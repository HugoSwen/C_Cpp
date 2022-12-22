#include <bits/stdc++.h>
#define ll long
#define K 1000000007
using namespace std;

int data[10005][3];
int main()
{
    int count = 0;
    int m, n;

    for (int i = 1; i <= count; i++)
    {
        n = data[1][0];
        m = data[1][1];
        cout << ((m + 1) * m + 8 * m) * (n * (n + 1) * (2 * n + 1) / 12 + (n + 1) * n / 4) + 12 * n * m << endl;
    }
    return 0;
}