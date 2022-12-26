#include <iostream>
using namespace std;

const int N = 100010;

char str[N];
int son[N][26], cnt[N], idx;
// idx记录当前创建到的节点的序号
// 0号点既是根节点，又是空节点
// son[][26]数组存储每个节点的子节点
// cnt数组存储每个节点作为字串结尾的次数

void insert(char str[])
{
    int sn = 0; // sn表示节点序号
    for (int i = 0; str[i]; i++)
    {
        int c = str[i] - 'a';
        if (!son[sn][c])
            son[sn][c] = ++idx;
        sn = son[sn][c];
    }

    cnt[sn]++;
}

int query(char str[])
{
    int sn = 0;
    for (int i = 0; str[i]; i++)
    {
        int c = str[i] - 'a';
        if (!son[sn][c])
            return 0;
        sn = son[sn][c];
    }

    return cnt[sn];
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    while (n--)
    {
        char op;
        cin >> op >> str;

        if (op == 'I')
            insert(str);
        else
            printf("%d\n", query(str));
            cout << query(str) << endl;
    }

    return 0;
}