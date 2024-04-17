#include <bits/stdc++.h>
using namespace std;

const int N = 70;

unordered_map<string, int> hs;

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        string str;
        string a;
        for (int i = 0; i < 8; i++)
        {
            cin >> a;
            str += a;
        }
        hs[str]++;
        printf("%d\n", hs[str]);
    }
    return 0;
}