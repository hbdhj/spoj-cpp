/*
6828. Lineup
Input:
1
100 0 0 0 0 0 0 0 0 0 0
0 80 70 70 60 0 0 0 0 0 0
0 40 90 90 40 0 0 0 0 0 0
0 40 85 85 33 0 0 0 0 0 0
0 70 60 60 85 0 0 0 0 0 0
0 0 0 0 0 95 70 60 60 0 0
0 45 0 0 0 80 90 50 70 0 0
0 0 0 0 0 40 90 90 40 70 0
0 0 0 0 0 0 50 70 85 50 0
0 0 0 0 0 0 66 60 0 80 80
0 0 0 0 0 0 50 50 0 90 88

Output:
970
*/
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int i,j,l,t;
    scanf("%d",&t);
    
    while(t--)
    {
        vector<vector<int> > pos(11, vector<int>(11, 0));
        for(i=0;i<11;i++)
        {
            for(j=0;j<11;j++)
            {
                scanf("%d",&pos[i][j]);
            }
        }
        for(i=1;i<11;i++)
        {
            for(j=0;j<11;j++)
            {
                if(pos[i][j])
                {
                    int max=0;
                    for(l=0;l<11;l++)
                        if(l!=j)
                            if(max<pos[i-1][l])
                                max=pos[i-1][l];
                    //printf("pos[%d][%d](%d)+=max(%d)\n",i,j,pos[i][j],max);            
                    pos[i][j]+=max;
                }
            }
        }
        int ret=0;
        for(i=0;i<11;i++)
        {
            if(ret<pos[10][i])
                ret=pos[10][i];
        }
        printf("%d\n",ret);
    }
    return 0;
}