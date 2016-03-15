/*
13399. Rachu
pre-computing
Input:
2 1
Output:
1
Input:
4 2
Output:
3
13399. Rachu
*/
#include <stdio.h>
#include <iostream>
#define M 10000007

using namespace std;

int ncr[100][100];

int main()
{
        ncr[1][0]=ncr[1][1]=1;
        for(int i=2;i<100;++i)
        {
            for(int j=0;j<i/2+1;++j)
            {
                ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%M;
                ncr[i][i-j]=ncr[i][j];
            }
        }
        int n,k;
		scanf("%d %d", &n, &k);
		if(n<k)
            printf("-1");
        else if(n==k)
            printf("1");
        else
            printf("%d\n", ncr[n-1][k-1]);
		//printf("%d\n", ncr[n-2][k-2]);
    	return 0;
}
