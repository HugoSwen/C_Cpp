# 点与线的操作

```cpp
const double eps = 1e-8;

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

```
