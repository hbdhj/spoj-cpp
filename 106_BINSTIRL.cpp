/*
106. Binary Stirling Numbers
S(0, 0) = 1,
S(n, 0) = 0, for n > 0,
S(0, m) = 0, for m > 0,
S(n, m) = m*S(n-1, m) + S(n-1, m-1), for n, m > 0.
Sample input:
1 
4 2 

Sample output:
1 
*/
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
/*int s(int n, int m)
{
    int ret;
    if((n==0)&&(m==0))
    {
        ret = 1;
    }
    else if((m==0)||(n==0))
    {
        ret = 0;
    }
    else if(m>n)
    {
        ret = 0;
    }
    else if(m==n)
    {
        ret = 1;
    }
    else
    {
        ret = m*s(n-1, m)+s(n-1, m-1);
    }
    //printf("s(%d, %d)=%d\n",n, m, ret);
    return ret;
}
int main()
{
    int i,t;
    scanf("%d",&t);
    vector<int> ns(t,0),ms(t,0);
    for(i=0;i<t;i++)
    {
        scanf("%d %d", &ns[i], &ms[i]);
    }
    for(i=0;i<t;i++)
    {
        printf("%d\n", s(ns[i], ms[i])%2);
    }
    return 0;
}*/
#include <stdio.h>

int main()
{
	int t, n, m;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		printf("%d\n", !((n-m)&((m-1)>>1)));
	}
	return 0;
}