/*
TASK: Possible Friends
ALGO: warshall
3
NYN
YNY
NYN
NYYY
YNNY
YNNN
YYNN
NNYNNNN
NNYNNNN
YYNYNNN
NNYNYNN
NNNYNYY
NNNNYNN
NNNNYNN
Output:
0 1
2 2
3 4
*/
#include <iostream>

using namespace std;

const int INF = 1000;

int main() 
{
	int test, n, i, j, k, g[50][50], best, idx, cnt;
	char str[64];
	scanf("%d", &test);
	while(test--) 
	{
		//init the friendship matrix
		scanf("%s", str);
		for(i = 0; str[i]; i++) 
		{
			g[0][i] = (str[i]=='Y')? 1 : INF;
		}
		//loop to change friendship status
		for(n = i, j = 1; j < n; j++) 
		{
			scanf("%s", str);
			for(i = 0; str[i]; i++) 
			{
				g[j][i] = (str[i]=='Y')? 1 : INF;
			}
		}
		//get the id with more friends
		best = idx = 0;
		for(k = 0; k < n; k++) 
		{
			for(cnt = i = 0; i < n; i++) 
			{
				if(k != i && g[k][i] == INF) 
				{
					for(j = 0; j < n; j++) 
					{
						if(i != j) 
						{
							if(g[k][j]!=INF && g[i][j]!=INF) break;
						}
					}
					if(j < n)
					{
						 cnt++;
					}
				}
			}
			if(cnt > best) 
			{
				best = cnt;
				idx = k;
			}
		}
		printf("%d %d\n", idx, best);
	}
	return 0;
}
