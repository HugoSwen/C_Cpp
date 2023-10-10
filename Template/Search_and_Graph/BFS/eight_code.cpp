#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<string, int> d;                     // 存储不同状态与初始状态的最短距离
queue<string> q;                                  // 宽搜的容器
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; // 坐标的变化

int bfs(string start)
{
    q.push(start); // 初始状态入队
    d[start] = 0;  // 初始状态与自身的距离为0

    string end = "12345678x"; // 结束状态

    while (!q.empty()) // 队列不为空时
    {
        auto t = q.front(); // 取队头进行扩展
        q.pop();

        int distance = d[t]; // 当前状态的距离

        if (t == end) // 若当前状态等于结束状态
            return distance;

        int p = t.find('x');        // x在当前状态中的一维坐标
        int a = p / 3, b = p % 3;   // 对应的二维坐标
        for (int i = 0; i < 4; i++) // 遍历四个可能的位置
        {
            int x = a + dx[i], y = b + dy[i];       // 可能达到的二维坐标
            int e = 3 * x + y;                      // 对应的一维坐标
            if (x >= 0 && x < 3 && y >= 0 && y < 3) // 坐标合法
            {
                swap(t[p], t[e]); // 交换x的位置
                if (!d.count(t))  // 交换之后的状态未搜索到
                {
                    d[t] = distance + 1; // 交换之后的距离
                    q.push(t);           // 新状态入队
                }
                swap(t[p], t[e]); // 恢复原状态， 继续遍历剩下的位置
            }
        }
    }

    return -1; // 没有达到结束状态
}

int main()
{
    string start;
    char c;
    for (int i = 1; i <= 9; i++)
    {
        cin >> c;
        start += c;
    }

    cout << bfs(start) << endl;
    return 0;
}