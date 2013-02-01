/*
3969. M&M Game
Sample input: 
2 
3 
3 5 1 
1 
1 
Sample output: 
John 
Brother 
*/

#include <stdio.h>
#include <vector>
//int ai[4747];
using namespace std;

int main()
{
    int t,n,m;
    scanf("%d",&t);
    vector<int> out(t);
    while(t--)
    {
        scanf("%d",&n);
        m=n;
        int ones=0;
        int ai(n);
        while(n--)
        {
            scanf("%d",&ai);
            if(ai==1)
                ones++;
            
        }
        if(ones==m)
        {
            if(ones%2==0)
                out[t]=0;   //printf("John\n");
            else
                out[t]=1;   //printf("Brother\n");
        }
        else
            out[t]=0;   //printf("John\n");
    }
    for(int i=out.size();i>0;i--)
    {
        if(out[i-1]==0)
            printf("John\n");
        else
            printf("Brother\n");
    }
    return 0;
}