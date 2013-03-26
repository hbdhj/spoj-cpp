/*
8665. Lucky Sequence Again
Sample Input:
4
1
3
10
18
Sample Output:
2
5
33
73
*/
#include <stdio.h>
#include <vector>
using namespace std;
main()
{
    int tn,i,j;
    scanf("%d", &tn);
    int *n=new int[tn];
    for(i=0;i<tn;i++)
        scanf("%d", &n[i]);
    for(i=0;i<tn;i++)
    {
        vector<int> p;
        while(n[i]>0)
        {
            switch(n[i]%4)
            {
                case 0:
                    p.push_back(7);
                    break;
                case 1:
                    p.push_back(2);
                    break;
                case 2:
                    p.push_back(3);
                    break;
                case 3:
                    p.push_back(5);
                    break;
            }            
            if(n[i]%4)    
                n[i]=n[i]/4;
            else
                n[i]=n[i]/4-1;
        }
        for(j=p.size();j>0;j--)
            printf("%d",p[j-1]);
        printf("\n");            
    }    
}