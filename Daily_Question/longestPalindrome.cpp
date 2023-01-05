#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int expandcentre(string s, int l, int r)
{
    while (l >= 0 && r < s.size() && s[l] == s[r])
    {
        l--;
        r++;
    }

    return r - l - 1;
}
string longestPalindrome(string s)
{
    int start = 0;
    int len1, len2, res = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        int len1 = expandcentre(s, i, i);
        int len2 = expandcentre(s, i, i + 1);
        int t = max(len1, len2);
        if (res < t)
        {
            res = t;
            start = i - (res - 1) / 2;
        }
    }

    return s.substr(start, res);
}

int main()
{
    string a = "babad";
    cout << longestPalindrome(a);
    return 0;
}