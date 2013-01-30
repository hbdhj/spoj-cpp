/*
12407. Johnny The Gambler
Sample Input
1
10 3 1 5 9
Sample Output
1. 1
*/

//#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int i,j,t,n,m;
	scanf("%d",&t);
	vector<int> xs(t,0);
	vector<vector<int> > ns(t, vector<int>(1000, 0));
	for(i=0;i<t;i++)
	{
		scanf("%d",&xs[i]);
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&m);
			ns[i][m]++;
		}
	}
	for(i=0;i<t;i++)
	{
		unsigned long long r=0;
		if(xs[i]%2==0)
		{
			if(xs[i]/2<1000)
			{
				for(j=xs[i]/2-1;(j>=0)&&((xs[i]-j)<1000);j--)
					r+=ns[i][j]*ns[i][xs[i]-j];
				r+=ns[i][xs[i]/2]*(ns[i][xs[i]/2]-1)/2;
			}
		}
		else
		{
			for(j=xs[i]/2;(j>=0)&&((xs[i]-j)<1000);j--)
				r+=ns[i][j]*ns[i][xs[i]-j];
		}
		printf("%d. %lld\n", i+1,r);
	}
	return 0;
}