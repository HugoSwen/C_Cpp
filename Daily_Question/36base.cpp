#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char str[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
unordered_map<char, int> rule;

vector<char> add(vector<char> &A, vector<char> &B)
{
    vector<char> res;
    for (int i = 0, t = 0; i < A.size() || i < B.size() || t; i++)
    {
        if (i < A.size())
            t += rule[A[i]];
        if (i < B.size())
            t += rule[B[i]];
        res.push_back(str[t % 36]);
        t /= 36;
    }

    return res;
}

int main()
{
    string a, b;
    cin >> a >> b;
    int i = 0;
    for (auto s : str)
        rule[s] = i++;
    vector<char> A, B;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i]);
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i]);

    vector<char> res = add(A, B);
    for (int i = res.size() - 1; i >= 0; i--)
        printf("%c", res[i]);

    return 0;
}