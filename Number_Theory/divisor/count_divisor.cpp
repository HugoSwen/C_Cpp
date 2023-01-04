#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;
const int N = 1e9 + 7;

unordered_map<int, int> primes;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int a;
        scanf("%d", &a);

        if (a == 1)
            continue;
        for (int i = 2; i <= a / i; i++)
        {
            if (a % i == 0)
            {
                while (a % i == 0)
                {
                    a /= i;
                    primes[i]++;
                }
            }
        }
        if (a > 1)
            primes[a]++;
    }

    LL res = 1;
    for (auto item : primes)
        res = res * (item.second + 1) % N;

    cout << res;
    return 0;
}