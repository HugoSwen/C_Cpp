#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;

    int carry = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size())
            carry += A[i];
        if (i < B.size())
            carry += B[i];
        C.push_back(carry % 10);

        carry /= 10; // 满10进1，不满则为0
        // 相同效果
        // if (carry >= 10)
        //     carry = 1;
        // else
        //     carry = 0;
    }

    if (carry)
        C.push_back(1);
    return C;
}

int main()
{
    string a, b;
    cin >> a >> b;

    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    return 0;
}