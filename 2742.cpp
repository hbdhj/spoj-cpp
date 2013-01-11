/*
2742. Summing Sums
Input:
3 4
1
0
4

Output:
26
25
29
The following is a table of the cows' numbers for each turn:

          Cows' numbers
Turn    Cow1  Cow2  Cow3
 0        1     0     4
 1        4     5     1
 2        6     5     9
 3       14    15    11
 4       26    25    29
*/

#define MOD 98765431

#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    unsigned long long int ci, sum;
    int i,n,t;
    scanf("%d %d", &n, &t);
    vector<unsigned long long int> cows(n);
    sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%llu", &cows[i]);
        sum+=cows[i];
    }
    //printf("Turn    Cow1  Cow2  Cow3\n");
    unsigned long long int total=1;
    int ti=t;
    while(ti--)
    {
        total*=(n-1);
    }
    unsigned long long int self;
    unsigned long long int other;
    if(t%2)
    {
        other=(total+1)/n;
        self=other-1;
    }
    else
    {
        other=(total-1)/n;
        self=other+1;
    }
    //printf("sum = %d, total = %llu, self = %llu, other = %llu\n",sum, total, self, other);
    for(i=0;i<n;i++)
    {
        printf("%llu\n",((sum-cows[i])*other+self*(cows[i]))%MOD);
    }
    
}
    return 0;