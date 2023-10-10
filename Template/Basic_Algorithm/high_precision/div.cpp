#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> div(vector<int> A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];  // 余数×权重10+该位数字
        C.push_back(r / b); // 存整除数
        r %= b;             // 改余数
    }
    reverse(C.begin(), C.end()); // 因为是按顺序存的，为统一格式翻转数组

    while (C.size() > 1 && C.back() == 0) // 去前导零
        C.pop_back();

    return C;
}

int main()
{
    string a;
    int b;
    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');

    int r;
    auto C = div(A, b, r);

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];

    cout << endl
         << r << endl;

    return 0;
}