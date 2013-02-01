/*
297. Aggressive cows
greedy
Input:
1
5 3
1
2
8
4
9
Output:
3
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int i,j,t,n,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&c);
        unsigned long long max=0;
        unsigned long long min=1000000000;
        vector<unsigned long long> stalls(n);
        for(i=0;i<n;i++)
        {
            scanf("%lld", &stalls[i]);
            if(min>stalls[i])
                min=stalls[i];
            if(max<stalls[i])
                max=stalls[i];    
        }
        unsigned long long interval = (max-min)/(c-1);
        /*printf("%lld %lld %lld\n", min, max, interval);
        for(i=0;i<n;i++)
        {
            printf("%lld ", stalls[i]);
        }
        printf("\n");*/
        sort(stalls.begin(),stalls.end());
        /*for(i=0;i<n;i++)
        {
            printf("%lld ", stalls[i]);
        }
        printf("\n");*/
        unsigned long long finterval=interval;
        unsigned long long former=min;
        unsigned long long expected=former+interval;
        for(i=1;i<n;i++)
        {
            if((expected>=stalls[i-1])&&(stalls[i]>=expected))
            {
                //printf("stalls[%d] = %lld, expected = %lld, stalls[%d] = %lld\n",i-1,stalls[i-1],expected,i,stalls[i]);
                if((expected-stalls[i-1])<=(stalls[i]-expected))
                {
                    if(finterval>(stalls[i-1]-former))
                        finterval=stalls[i-1]-former;
                    former=stalls[i-1];
                }
                else
                {
                    if(finterval>(stalls[i]-former))
                        finterval=stalls[i]-former;
                    former=stalls[i];
                }
                expected=former+interval;
            }
        }
        
        printf("%lld\n", finterval);
    }
    return 0;
}