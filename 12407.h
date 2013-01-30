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
	vector<vector<int> > ns(t, vector<int>(3001, 0));
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
		for(j=0;j<xs[i]/2;j++)
			r+=ns[i][j]*ns[i][xs[i]-j];
		if(xs[i]%2==0)
		{
			r+=ns[i][xs[i]%2]*(ns[i][xs[i]%2]-1)/2;
		}
		printf("%d. %lld\n", i+1,r);
	}
	return 0;
}