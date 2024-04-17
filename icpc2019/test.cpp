#include <iostream>
using namespace std;

int main()
{
    string t;
    int mlen = 0;
    int st = 4;
    cin >> t;
    cout << t.size() + st << endl;
    if (t.size() + st - 1 > mlen)
        mlen = t.size() + st - 1;
    cout << mlen << endl;
    return 0;
}