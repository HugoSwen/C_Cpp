#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-6;

int n;
double a[105][105];

int gauss()
{
    int c, r;
    for (c = 0, r = 0; c < n; c++)
    {
        int t = r; // 找到当前列绝对值最大数的行号
        for (int i = r + 1; i < n; i++)
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        if (fabs(a[t][c]) < eps) // 当前列全是0 不需要操作
            continue;

        for (int i = c; i < n + 1; i++) // 交换该行与目标行的数
            swap(a[r][i], a[t][i]);
        for (int i = n; i >= c; i--) // 通过初等变换将该行该列的数变成1
            a[r][i] /= a[r][c];
        for (int i = r + 1; i < n; i++) // 通过初等变化将该行该列以下的数全部变为0
            if (fabs(a[i][c]) > eps)    // 已经是0就不需要处理
                for (int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c];
        r++; // 进入到下一行
    }

    if (r < n) // 没有处理完所有行
    {
        for (int i = r; i < n; i++)
            if (fabs(a[i][n]) > eps) // 出现0 = 非零 无解
                return 2;
        return 1; // 0 = 0 无穷多组解
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--) // 消去该行非xi的未知数
            a[i][n] -= a[i][j] * a[j][n];
        if (fabs(a[i][n]) < eps)
            a[i][n] = 0; // 防止输出-0.00
    }

    return 0; // 有唯一解
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            cin >> a[i][j];

    int c = gauss();
    if (c == 0)
        for (int i = 0; i < n; i++)
            printf("%.2f\n", a[i][n]);
    else if (c == 1)
        puts("Infinite group solutions");
    else
        puts("No solution");

    return 0;
}