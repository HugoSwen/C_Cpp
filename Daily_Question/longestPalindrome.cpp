#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int expandcentre(string s, int l, int r) // 由中心向两边扩散
{
    while (l >= 0 && r < s.size() && s[l] == s[r]) // 扩散的两个位置要相等才能继续扩散
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
        int len1 = expandcentre(s, i, i);     // 单中心
        int len2 = expandcentre(s, i, i + 1); // 双中心
        int t = max(len1, len2);
        if (res < t)
        {
            res = t;
            start = i - (res - 1) / 2; // 奇数偶数统一化，不需要写if else 注意学习
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