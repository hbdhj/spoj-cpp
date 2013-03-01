/*
1805. Largest Rectangle in a Histogram
input
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0
output
8
4000
*/
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n>0)
    {
        vector<long> hlist(n);
        for(int i=0;i<n;i++)
        {
            scanf("%ld",&hlist[i]);
        }
        long long max=hlist[0];
        for(int i=0;i<n;)
        {
            long min=hlist[i];
            long long area=hlist[i];
            long long local_max_area=hlist[i];
            for(int j=i;j<n;)
            {
                if(hlist[j]<min)
                    min=hlist[j]
                area=min*(j-i+1);
                if(area>local_max_area)
                {
                    local_max_area=area;
                    j++;
                }
                else
                {
                    i++;
                    break;
                }    
            }
        }
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}