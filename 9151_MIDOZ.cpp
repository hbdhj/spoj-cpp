/*
TASK: Kids Love Candies
Input:
2
3 2
4 5 7
3 8
4 5 7
Output: 
7
0
*/

#include <stdio.h>
int main()
{
    int i,j,tN,n,k,m;
    scanf("%d",&tN);
    int* p=new int[tN];
    for(i=0;i<tN;i++)
    {
        scanf("%d %d",&n, &k);
        p[i]=0;
        for(j=0;j<n;j++)
        {
            scanf("%d", &m);
            p[i]+=m/k;
        }
    }
    for(i=0;i<tN;i++)
        printf("%d\n", p[i]);
    delete p;
    return 0;
}
