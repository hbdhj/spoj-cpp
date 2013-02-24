/*
7588. Wise And Miser
Input:
5 5
1 3 1 2 6
10 2 5 4 15
10 9 6 7 1
2 7 1 5 3
8 2 6 1 9

Output:
10

Explanation: 
1->4->1->3->1 = 10
*/
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b, int c)
{
	int d=a>b?b:a;
	return d>c?c:d;
}

int main()
{
	int i,j,n,m;
	scanf("%d %d", &n, &m);
	vector<vector<int> > bus(n,vector<int>(m,0));
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d", &bus[i][j]);
		}
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(j==0)
			{
				bus[i][0]+=bus[i-1][0]>bus[i-1][1]?bus[i-1][1]:bus[i-1][0];
			}
			else if(j==(m-1))
			{
				bus[i][m-1]+=bus[i-1][m-1]>bus[i-1][m-2]?bus[i-1][m-2]:bus[i-1][m-1];
			}
			else
			{
				bus[i][j]+=min(bus[i-1][j-1],bus[i-1][j],bus[i-1][j+1]);
			}
			//printf("%d ", bus[i][j]);
		}
		//printf("\n");
	}
	int path=0;
	for(j=0;j<m;j++)
	{
		if((path==0)||(path>bus[n-1][j]))
		{
			path=bus[n-1][j];
		}
	}
	printf("%d\n", path);
	return 0;
}