/*
9788. Friends of Friends
Input:
3
2334 5 1256 4323 7687 3244 5678
1256 2 2334 7687
4323 5 2334 5678 6547 9766 9543
Output:
6
*/
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int i,j,n,f,m,ff;
	scanf("%d", &n);
	vector<int> ffs(10000,0);
	for(i=0;i<n;i++)
	{
		scanf("%d", &f);
		scanf("%d", &m);
		ffs[f]=2;
		for(j=0;j<m;j++)
		{
			scanf("%d", &ff);
			if(ffs[ff]==0)
				ffs[ff]=1;
		}		
	}
	int total=0;
	for(i=0;i<10000;i++)
	{
		if(ffs[i]==1)
			total+=ffs[i];
	}
	
	printf("%d\n",total);
	return 0;
}