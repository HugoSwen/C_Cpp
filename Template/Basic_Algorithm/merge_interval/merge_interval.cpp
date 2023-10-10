#include <iostream>
#include <vector>
#include <algorithm>
#define PII pair<int, int>

using namespace std;

int n;
vector<PII> segs;

void merge_interval(vector<PII> &segs)
{
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
    {
        if (ed < seg.first)
        {
            if (st != -2e9) // 排除初始区间
                res.push_back({st, ed});

            st = seg.first, ed = seg.second;
        }
        else
            ed = max(ed, seg.second);
    }

    if (st != -2e9) // 排除
        res.push_back({st, ed});

    segs = res;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    merge_interval(segs);

    cout << segs.size();

    return 0;
}