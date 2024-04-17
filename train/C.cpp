#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int n;
double ans = 1e20;

struct Point
{
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    void read() { scanf("%lf%lf", &x, &y); }
    double get_dis(const Point &b) { return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y)); }
};

struct cmp_x
{
    bool operator()(const Point &a, const Point &b) const
    {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct cmp_y
{
    bool operator()(const Point &a, const Point &b) const { return a.y < b.y; }
};

void upd_ans(Point a, Point b)
{
    double dist = a.get_dis(b);
    if (ans > dist)
        ans = dist;
}

Point a[N];
multiset<Point, cmp_y> s;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        a[i].read();
    sort(a, a + n, cmp_x());

    for (int i = 0, l = 0; i < n; i++)
    {
        while (l < i && a[i].x - a[l].x >= ans)
            s.erase(s.find(a[l++]));
        for (auto it = s.lower_bound(Point(a[i].x, a[i].y - ans));
             it != s.end() && it->y - a[i].y < ans; it++)
            upd_ans(*it, a[i]);
        s.insert(a[i]);
    }
    printf("%.4lf", ans);
    return 0;
}