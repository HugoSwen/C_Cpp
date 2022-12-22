#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int q[N], tmp[N];

void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int mid = l + r >> 1; // 分界点
    // 递归排序
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    //       左半边起点  右半边起点
    while (i <= mid && j <= r) // 其中有一方遍历结束
        // 取小
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
        {
            tmp[k++] = q[j++];
            // ans += (mid - i + 1); 逆序对计算
        }

    // 加入原序列中未遍历的部分
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    // 将临时数组中的序列存入原数组
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    merge_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);

    return 0;
}