/*
11462. Fun with Fibonacci Series (Challenge)
Input:
2
2 2 10 21
1 3 10 21
Output:
13
4
*/
#include <iostream>
#include <vector>

using namespace std;

long Fibonacci(long a, long b, long n, long m)
{
    long sum=a+b;
    for(int i=2;i<n;i++)
    {
        if(i%2)
        {
            b=(a+b)%m;
            sum=(sum+b)%m;
        }
        else
        {
            a=(a+b)%m;
            sum=(sum+a)%m;
        }    
    }
    return sum%m;
};

int main()
{
    int i, tN;
    scanf("%d", &tN);
    vector<long> as(tN), bs(tN), ns(tN), ms(tN);
    for(i=0;i<tN;i++)
    {
        scanf("%ld %ld %ld %ld", &as[i], &bs[i], &ns[i], &ms[i]);
    }
    for(i=0;i<tN;i++)
    {
        printf("%ld\n", Fibonacci(as[i], bs[i], ns[i], ms[i]));
    }
    
    return 0;
}