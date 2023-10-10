#include <iostream>
#include <string>
using namespace std;

char stk[105]; // 字符数组实现栈
int st = -1;   // 栈顶

bool is_match(char left, char right) // 判断栈顶与当前右括号是否匹配
{
    return (left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}');
}

bool check(string s) // 判断字符串中括号是否匹配
{
    for (char c : s) // 遍历每一个字符
    {
        if (c == '(' || c == '[' || c == '{')      // 如果是左括号则进栈
            stk[++st] = c;                         // 栈顶先自增再赋值
        else if (c == ')' || c == ']' || c == '}') // 如果是右括号则判断是否和栈顶匹配
        {
            if (st == -1 || !is_match(stk[st], c)) // 如果栈空或者与栈顶不匹配
                return false;
            st--; // 栈顶退栈
        }
    }
    return st == -1; // 返回栈是否为空，为空则匹配，非空则不匹配
}

int main()
{
    string s;
    getline(cin, s);
    cout << (check(s) ? "yes" : "no") << endl;
    return 0;
}