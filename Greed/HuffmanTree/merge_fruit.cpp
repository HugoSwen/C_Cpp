/*
排序不等式证明
*/
#include <iostream>
#include <queue>
using namespace std;

int n;

int main()
{
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> heap;
    while (n--)
    {
        int a;
        scanf("%d", &a);
        heap.push(a);
    }

    int res = 0;
    while (heap.size() > 1)
    {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();
        res += a + b;
        heap.push(a + b);
    }

    cout << res << endl;
    return 0;
}