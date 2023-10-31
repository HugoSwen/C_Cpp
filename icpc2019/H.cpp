#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e3 + 10, mod = 1e9 + 7, dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

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

    double get_dis(const Point &b) { return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y)); } // 求两点间的距离
    // double get_dis(const Point& b) { return hypot(x - b.x, y - b.y); }  // 求两点间的距离的平方
    double get_dis2(const Point &b) { return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y); } // 求两点间的距离的平方
};                                                                                            // 点、起点在原点的向量

Point get_mid(Point A, Point B) { return (A + B) * 0.5; } // 求线段AB中点

double get_area(Point A, Point B, Point C) { return fabs((B - A) ^ (C - A) * 0.5); }

struct Line
{
    Point ST, ED;

    Line() {}
    Line(Point _A, Point _B) : ST(_A), ED(_B) {}
    Line(double a, double b, double c, double d) : ST(a, b), ED(c, d) {}

    bool is_point_on_segment(Point P)
    { // P是否在线段AB上
        return sgn((P - ST) ^ (ED - ST)) == 0 && sgn((P - ST) * (P - ED)) <= 0;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Point A, B, C, P;
        A.read(), B.read(), C.read(), P.read();
        Line AB(A, B), AC(A, C), BC(B, C);

        bool flag1 = AB.is_point_on_segment(P), flag2 = BC.is_point_on_segment(P), flag3 = AC.is_point_on_segment(P);
        if (!flag1 && !flag2 && !flag3)
        { // 无解
            cout << -1 << endl;
            continue;
        }

        double area = get_area(A, B, C) * 0.5; // ABC面积的一半

        if (flag1)
        { // P在AB上
            if (P.get_dis2(A) < P.get_dis2(B))
            {
                Point L = B, R = C, MID;
                int t = 50; // 二分次数
                while (t--)
                {
                    MID = get_mid(L, R);
                    double s = get_area(P, MID, B);
                    int flag = sgn(s - area);
                    if (flag == 0)
                        break;
                    else if (flag == 1)
                        R = MID;
                    else
                        L = MID;
                }
                printf("%.10lf %.10lf\n", MID.x, MID.y);
            }
            else
            {
                Point L = A, R = C, MID;
                int t = 50; // 二分次数
                while (t--)
                {
                    MID = get_mid(L, R);
                    double s = get_area(P, MID, A);
                    int flag = sgn(s - area);
                    if (flag == 0)
                        break;
                    else if (flag == 1)
                        R = MID;
                    else
                        L = MID;
                }
                printf("%.10lf %.10lf\n", MID.x, MID.y);
            }
        }
        else if (flag2)
        { // P在BC上
            if (P.get_dis2(B) < P.get_dis2(C))
            {
                Point L = C, R = A, MID;
                int t = 50; // 二分次数
                while (t--)
                {
                    MID = get_mid(L, R);
                    double s = get_area(P, MID, C);
                    int flag = sgn(s - area);
                    if (flag == 0)
                        break;
                    else if (flag == 1)
                        R = MID;
                    else
                        L = MID;
                }
                printf("%.10lf %.10lf\n", MID.x, MID.y);
            }
            else
            {
                Point L = B, R = A, MID;
                int t = 50; // 二分次数
                while (t--)
                {
                    MID = get_mid(L, R);
                    double s = get_area(P, MID, B);
                    int flag = sgn(s - area);
                    if (flag == 0)
                        break;
                    else if (flag == 1)
                        R = MID;
                    else
                        L = MID;
                }
                printf("%.10lf %.10lf\n", MID.x, MID.y);
            }
        }
        else
        { // P在AC上
            if (P.get_dis2(A) < P.get_dis2(C))
            {
                Point L = C, R = B, MID;
                int t = 50; // 二分次数
                while (t--)
                {
                    MID = get_mid(L, R);
                    double s = get_area(P, MID, C);
                    int flag = sgn(s - area);
                    if (flag == 0)
                        break;
                    else if (flag == 1)
                        R = MID;
                    else
                        L = MID;
                }
                printf("%.10lf %.10lf\n", MID.x, MID.y);
            }
            else
            {
                Point L = A, R = B, MID;
                int t = 50; // 二分次数
                while (t--)
                {
                    MID = get_mid(L, R);
                    double s = get_area(P, MID, A);
                    int flag = sgn(s - area);
                    if (flag == 0)
                        break;
                    else if (flag == 1)
                        R = MID;
                    else
                        L = MID;
                }
                printf("%.10lf %.10lf\n", MID.x, MID.y);
            }
        }
    }

    return 0;
}