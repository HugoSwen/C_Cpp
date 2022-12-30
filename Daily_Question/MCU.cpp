#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;

int n, mttn, ttn[N];
LL sum;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &ttn[i]);
    
    sort(ttn, ttn + n);
    
    for (int i = 0; i < n; i++)
    {
        if(ttn[i] > mttn && (LL)ttn[i] * (n - i) > sum)
        {
            mttn = ttn[i];
            sum = (LL)ttn[i] * (n - i);
        }
    }

    printf("%lld %d", sum, mttn);
    
    return 0;
}