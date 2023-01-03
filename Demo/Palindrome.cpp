#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char str[100];
    gets(str);
    string res, s;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];
        if (isdigit(c) || isalpha(c))
            res += tolower(c);
    }
    s = res;
    reverse(s.begin(), s.end());

    if (res == s)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
