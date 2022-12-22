#include <iostream>
using namespace std;

const int N = 10000;

int main()
{
    double x;
    cin >> x;

    double l = -N, r = N;
    // 使区间足够小
    // for(int i = 0; i < 100; i++)循环一百次
    const double eps = 1e-8;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x)
            r = mid;
        else
            l = mid;
    }

    printf("%.6lf", l);
    return 0;
}