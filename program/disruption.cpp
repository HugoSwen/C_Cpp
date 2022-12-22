#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long cap;
    long level = 0;
    cin >> cap;
    long m = (int)sqrt(cap);
    for (int i = 1; i <= m; i++)
    {
        if (cap % i == 0)
        {
            level += i + cap / i;
        }
    }
    if (m * m == cap)
    {
        level -= m;
    }
    cout << level;
    return 0;
}
