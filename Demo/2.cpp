#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> hs; // 定义哈希表
int n, k, d, m;                // 飞行记录数 最低里程 飞行里程 总询问数
string str;                    // 字符ID

int main()
{
    cin >> n >> k;
    while (n--)
    {
        cin >> str >> d;
        if (d < k)
            d = k;  // 小于k当k计
        hs[str] += d; // 对应的ID加上里程
    }

    cin >> m;
    while (m--)
    {
        cin >> str;
        if (!hs.count(str)) // 不存在该ID的记录
            printf("No Info\n");
        else
            printf("%d\n", hs[str]);
    }
    return 0;
}