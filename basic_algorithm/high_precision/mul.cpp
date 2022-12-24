#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int> A, int b)
{
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * b;   // 进位加上每一位与b相乘的结果
        C.push_back(t % 10); // 存个位
        t /= 10;             // 删个位
    }

    // 与 ||t 起到相同效果
    // while (t)
    // {
    //     C.push_back(t % 10);
    //     t /= 10;
    // }

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

    auto C = mul(A, b);

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];

    return 0;
}