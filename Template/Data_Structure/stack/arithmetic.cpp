#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}}; // 符号优先级
stack<int> num;                                                      // 数栈
stack<char> op;                                                      // 符栈

void eval() // 数栈pop两个数，符栈pop一个运算符
{
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    char c = op.top();
    op.pop();

    int res;
    if (c == '+')
        res = a + b;
    else if (c == '-')
        res = a - b;
    else if (c == '*')
        res = a * b;
    else
        res = a / b;

    num.push(res); // 将计算结果push回数栈
}

int main()
{
    string eps;
    cin >> eps;

    for (int i = 0; i < eps.size(); i++) // 遍历表达式的每一个符号，做对应处理
    {
        char c = eps[i];
        if (isdigit(c)) // 符号是数字
        {
            int x = 0;
            while (i < eps.size() && isdigit(eps[i])) // 多位数转化
                x = x * 10 + eps[i++] - '0';
            num.push(x); // 数字push数栈
            i--;         // 由于此次循环结束i会自增 所以这里自减一次
        }
        else if (c == '(') // 符号是左括号
            op.push(c);    // push符栈，方便右括号的计算
        else if (c == ')') // 符号是右括号
        {
            while (op.top() != '(') // 计算出这两个括号包围起来的算式
                eval();
            op.pop(); // pop左括号
        }
        else // 符号是运算符
        {
            while (op.size() && pr[c] <= pr[op.top()]) // 符栈不为空并且栈顶元素优先级大于等于待处理的运算符
                eval();
            op.push(c); // 处理结束，将运算符push符栈
        }
    }
    while (op.size()) // 所有处理结束，将符栈内剩余符号处理
        eval();

    cout << num.top() << endl; // 数栈的栈顶元素(仅剩一个元素)即为运算结果
    return 0;
}