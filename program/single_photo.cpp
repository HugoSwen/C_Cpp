#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{

    int N;
    cin >> N;
    string sequence;
    cin >> sequence;
    ll ans = 0;
    int front, rear;
    for (int i = 0; i < N; i++)
    {
        front = rear = 0;
        for (int f = i - 1; f >= 0; f--)
        {
            if (sequence[f] != sequence[i])
                front++;
            else
                break;
        }
        for (int r = i + 1; r < N; r++)
        {
            if (sequence[r] != sequence[i])
                rear++;
            else
                break;
        }
        if (front + rear >= 2)
        {
            ans += (ll)front * rear + max(front - 1, 0) + max(rear - 1, 0);
        }
    }
    cout << ans << endl;
    return 0;
}