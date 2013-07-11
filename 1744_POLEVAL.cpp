/*
TASK: Evaluate the polynomial
Input:
2
1 -2 -1
5
0 1 -1 2 -2
3
2 1 -2 -1
4
0 -1 2 -2
-1

Output:
Case 1:
-1
-2
2
-1
7
Case 2:
-1
0
15
-9
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i, j, n, ci, k, xi, l;    
    scanf("%d", &n);
    vector<int> nl;
    vector<int> kl;
    vector<vector<int> > cll;    
    vector<vector<int> > xll;    
    while(n!=-1)
    {
        nl.push_back(n); 
        vector<int> cl(n+1,0);    
        for(j=n;j>=0;j--)
            scanf("%d", &cl[j]);
        cll.push_back(cl);  
        //printf("dp1\n");        
        scanf("%d", &k);
        //printf("dp2\n");
        kl.push_back(k); 
        vector<int> xl(k,0);
        for(j=0;j<k;j++)
            scanf("%d", &xl[j]);
        xll.push_back(xl); 
        //printf("dp3\n");
        scanf("%d", &n);        
    }
    
    for(i=0;i<nl.size();i++)
    {
        printf("Case %d:\n",i+1);
        for(j=0;j<xll[i].size();j++)
        {
            //printf("Now caculate %d:", xll[i][j]);
            int ret=0;
            ret = cll[i][0];
            if(xll[i][j])
            {
                int base=1;
                for(k=nl[i];k>0;k--)
                {
                    //printf("%d ", cll[i][k]);
                    printf("ret = %d,base = %d, c[%d]=%d   ",ret,base,nl[i]-k,cll[i][k]);
                    base *= xll[i][j];
                    ret += base*cll[i][k];
                    printf("ret = %d,base = %d, c[%d]=%d\n",ret,base,nl[i]-k,cll[i][k]);
                }
            }
            printf("%d\n", ret);
        }
    }
    return 0;
}
