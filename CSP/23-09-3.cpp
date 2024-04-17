#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m;
int num, a[N];

void stringSplit(string str, const const char split, vector<string>& res)
{
    istringstream iss(str);
    string token;
    while (getline(iss, token, split))
        res.push_back(token);
}

int main()
{
    scanf("%d%d", &n, &m);
    string str;
    vector<string> split;
    getline(cin, str);
    stringSplit(str, ' ', split);

    // .......

    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &num);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        
        stack<string> stk;
        
    }
    return 0;
}