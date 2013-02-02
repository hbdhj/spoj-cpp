/*
6256. Inversion Count
Input:
2
3
3
1
2
5
2
3
8
6
1
Output: 
2
5
*/
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int i,j,k,t,n;
	scanf("%d",&t);
	vector<vector<int> > inputs;
	while(t--)
	{
		scanf("%d",&n);
		vector<int> in(n);
		for(i=0;i<n;i++)
			scanf("%d",&in[i]);
		inputs.push_back(in);	
	}
	for(i=0;i<inputs.size();i++)
	{
		int ret=0;
		//printf("%d\n",ret);
		for(j=0;j<inputs[i].size()-1;j++)
		{
			for(k=j+1;k<inputs[i].size();k++)
			{
				//printf("Checking inputs[%d][%d] = %d and inputs[%d][%d] = %d\n",i,j,inputs[i][j],i,k,inputs[i][k]);
				if(inputs[i][j]>inputs[i][k])
				{
					ret++;
					//printf("ret = %d\n",ret);
				}	
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}