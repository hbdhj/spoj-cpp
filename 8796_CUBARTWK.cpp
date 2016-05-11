/*
TASK: Cubist Artwork
ALGO: sort, merge
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	while(n&&m)
	{
		vector<int> hf(n, 0);
		for(int i=0; i<n; i++)
		{
			scanf("%d", &hf[i]);
		}
		vector<int> hs(m, 0);
		for(int j=0; j<m; j++)
		{
			scanf("%d", &hs[j]);
		}
		sort(hf.begin(), hf.end());
		sort(hs.begin(), hs.end());
		int i=n-1, j=m-1, ret=0;
		while(i>=0&&j>=0)
		{
			//printf("L32 hf[%d] = %d, fs[%d] = %d, ret = %d\n", i, hf[i], j, hs[j], ret);
			if(hf[i]>hs[j])
			{
				ret+=hf[i];
				i--;
			}
			else if(hf[i]<hs[j])
			{
				ret+=hs[j];
				j--;
			}
			else
			{
				ret+=hs[j];
				j--;
				i--;
			}
		}
		while(i>=0)
		{
			ret+=hf[i];
			i--;
		}
		while(j>=0)
		{
			ret+=hs[j];
			j--;
		}
		printf("%d\n", ret);
		scanf("%d %d", &n, &m);
	}
	return 0;
}
