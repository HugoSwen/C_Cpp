#include <iostream>
#include <bitset>
using namespace std;

int lowbit(int x)
{
    return x & -x;
}

void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}

int m = 10, n = 20;

int main()
{
    int a = 0b1010;
    cout << bitset<16>(~a) << endl;
    cout << bitset<16>(lowbit(a)) << endl;
    cout << m << " " << n << endl;
    swap(m, n);
    cout << m << " " << n;
    return 0;
}