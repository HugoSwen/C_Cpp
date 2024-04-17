#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-8;
const int N = 105;

int cmp(double x, double y)
{ // 比较浮点数
    if (fabs(x - y) < eps)
        return 0; // 相等
    return x < y ? -1 : 1;
}

int sgn(double x)
{ // 符号函数
    if (fabs(x) < eps)
        return 0; // 0
    return x < 0 ? -1 : 1;
}

struct Point
{
    double x, y;

    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}

    void read() { scanf("%lf%lf", &x, &y); }

    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    double operator*(const Point &b) const { return x * b.x + y * b.y; } // 点积
    double operator^(const Point &b) const { return x * b.y - y * b.x; } // 叉积
    Point operator*(const double &k) const { return Point(x * k, y * k); }
    bool operator==(const Point &b) const { return !cmp(x, b.x) && !cmp(y, b.y); }
};

struct Line
{
    Point ST, ED;

    Line() {}
    Line(Point _A, Point _B) : ST(_A), ED(_B) {}
    Line(double a, double b, double c, double d) : ST(a, b), ED(c, d) {}
};

Point pnt[2 * N];
int n;

bool checkIntersect(Line line, Line seg)
{
    Point a = line.ST, b = line.ED, c = seg.ST, d = seg.ED;
    // 叉积的点积
    return ((c - a) ^ (b - a)) * ((d - a) ^ (b - a)) <= eps;
}

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i += 2)
        pnt[i].read(), pnt[i + 1].read();

    for (int i = 1; i <= 2 * n - 1; i++)
        for (int j = i + 1; j <= 2 * n; j++)
        {
            if (pnt[i] == pnt[j])
                continue;
            Line line = Line(pnt[i], pnt[j]);
            bool sign = true;
            for (int k = 1; k <= 2 * n - 1; k += 2)
            {
                if (!checkIntersect(line, Line(pnt[k], pnt[k + 1])))
                {
                    sign = false;
                    break;
                }
            }

            if (sign)
            {
                printf("Yes!\n");
                return;
            }
        }

    printf("No!\n");
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}