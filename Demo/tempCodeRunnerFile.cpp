#include <iostream>
#include <unordered_map>
using namespace std;

char stk[105], str[105];
int sh = 0, st = -1;
unordered_map<char, int> pr;

int main()
{
    pr['{'] = 3;
    pr['}'] = 3;
    pr['['] = 2;
    pr[']'] = 2;
    pr['('] = 1;
    pr[')'] = 1;

    scanf("%s", str);
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            if (pr[stk[st]] < pr[str[i]])
            {
                printf("no");
                return 0;
            }
            stk[++st] = str[i];
        }
            
        else if (str[i] == '}' || str[i] == ']' || str[i] == ')')
            if (pr[stk[st]] != pr[str[i]])
            {
                printf("no");
                return 0;
            }
            else st--;
    }

    printf("yes");
    return 0;
}