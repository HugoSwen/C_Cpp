/*
 * 1. 每两个方程为一组，由扩展欧几里得算法得到方程的特解k1,k2，若m2 - m1不是a1 a2最大公约数的倍数则无解
 * 2. 扩大相应倍数后写出通解nk1 + a2/d * t
 * 3. 由通解求出k1最小非负整数解以防止溢出
 * 4. 更新m1 += k1 * a1, a1 *= a2 / d，即合并了这两个方程
 * 5. 若还有方程，回到1
 */
#include <iostream>
using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }

    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    int n;
    LL a1, a2, m1, m2;
    cin >> n;
    cin >> a1 >> m1;
    n--; // 预处理减去一次

    bool has_answer = true; // 有无解的标志
    while (n--)
    {
        cin >> a2 >> m2;

        LL k1, k2;
        LL d = exgcd(a1, a2, k1, k2);
        if ((m2 - m1) % d) // m2 - m1不是a1 a2最大公约数的倍数则无解
        {
            has_answer = false;
            break;
        }

        k1 *= (m2 - m1) / d; // k1是使结果为d的值，需要乘以倍数
        LL t = a2 / d;
        k1 = (k1 % t + t) % t; // 由通解公式找到k1的最小非负整数解，以防止m1的溢出
        m1 = k1 * a1 + m1;     // 更新m1的值
        a1 *= t;               // 更新a1的值，即a1 a2的最小公倍数
    }

    if (has_answer)
        cout << m1 % a1; // x = ka1 + m1，此时a1是 a1~an n个数的最小公倍数
    else
        puts("-1");

    return 0;
}