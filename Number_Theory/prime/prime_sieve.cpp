/*
1:朴素筛法.
(1).做法:把2~(n-1)中的所有的数的倍数都标记上,最后没有被标记的数就是质数.
(2).原理:假定有一个数p未被2~(p-1)中的数标记过,那么说明,不存在2~(p-1)中的任何一个数的倍数是p,
也就是说p不是2~(p-1)中的任何数的倍数,也就是说2~(p-1)中不存在p的约数,因此,根据质数的定义可知:
p是质数.
(3).调和级数:当n趋近于正无穷的时候,1/2+1/3+1/4+1/5+…+1/n=lnn+c.(c是欧阳常数,约等于0.577左右.).
(4).底数越大,log数越小
(4).时间复杂度:约为O(nlogn);(注:此处的log数特指以2为底的log数).
2:埃氏筛(稍加优化版的筛法).
(1).质数定理:1~n中有n/lnn个质数.
(2).原理:在朴素筛法的过程中只用质数项去筛.
(3).时间复杂度:粗略估计:O(n).实际:O(nlog(logn)).
(4).1~n中,只计算质数项的话,”1/2+1/3+1/4+1/5+…+1/n”的大小约为log(logn).
3:线性筛
(1).若n在10的6次方的话,线性筛和埃氏筛的时间效率差不多,若n在10的7次方的话,线性筛会比埃氏筛快了大概一倍.
(2).思考:一:线性筛法为什么是线性的?
二:线性筛法的原理是什么?
(3).核心:1~n内的合数p只会被其最小质因子筛掉.
(4).原理:1~n之内的任何一个合数一定会被筛掉,而且筛的时候只用最小质因子来筛,
然后每一个数都只有一个最小质因子,因此每个数都只会被筛一次,因此线性筛法是线性的.
(5).枚举到i的最小质因子的时候就会停下来,即”if(i%primes[j]==0) break;”.
(6).因为从小到大枚举的所有质数,所以当”i%primes[j]!=0”时,primes[j]一定小于i的最小质因子,
primes[j]一定是primes[j]i的最小质因子.
(7).因为是从小到大枚举的所有质数,所以当”i%primes[j]==0”时,primes[j]一定是i的最小质因子,
而primes[j]又是primes[j]的最小质因子,因此primes[j]是iprimes[j]的最小质因子.
(8).关于for循环的解释:
注:首先要把握住一个重点:我们枚举的时候是从小到大枚举的所有质数
1.当i%primes[j]==0时,因为是从小到大枚举的所有质数,所以primes[j]就是i的最小质因子,而primes[j]又是其本身
primes[j]的最小质因子,因此当i%primes[j]==0时,primes[j]是primes[j]i的最小质因子.
2.当i%primes[j]!=0时,因为是从小到大枚举的所有质数,且此时并没有出现过有质数满足i%primes[j]==0,
因此此时的primes[j]一定小于i的最小质因子,而primes[j]又是其本身primes[j]的最小质因子,
所以当i%primes[j]!=0时,primes[j]也是primes[j]i的最小质因子.
3.综合1,2得知,在内层for循环里面无论何时,primes[j]都是primes[j]i的最小质因子,因此”st[primes[j]i]=true”
语句就是用primes[j]i这个数的最小质因子来筛掉这个数.
*/
#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int cnt, primes[N];
bool st[N];

int simple(int n) // 朴素筛法
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            cnt++;
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }

    return cnt;
}

int Eratos(int n) // 埃氏筛法
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            cnt++;
            for (int j = i + i; j <= n; j += i)
                st[j] = true;
        }
    }

    return cnt;
}

int linear(int n) // 线性筛法
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }

    return cnt;
}

int main()
{
    int n;
    cin >> n;
    cout << linear(n);
    return 0;
}