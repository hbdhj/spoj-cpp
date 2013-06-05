/*
TASK: Roads in Berland
ALGO: warshall
Input:
3
0 4 5
4 0 9
5 9 0
2
2 3 8
1 2 1

Output:
17 
12
// 17= 4+5+8
// 12 = 1+5+6(1+5)
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 303;

int a[MAX][MAX];

void warshall(int n) 
{
	int i, j, k;
	for(k = 0; k < n; k++)
	{
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
}

void myfunc(int n, int u, int v) 
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			a[i][j] = a[j][i] = min(a[i][u] + a[u][v] + a[v][j], a[i][j]);
		}
	}
}

int main() 
{
	int i, j, u, v, w, tot;
	int n, q;
	scanf("%d", &n);
	//init the distance matrix
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	// get the shortest path
	warshall(n);
	scanf("%d", &q);
	while(q--) 
	{
		scanf("%d%d%d", &u, &v, &w);
		u--; 
		v--; 
		tot = 0;
		a[v][u] = a[u][v] = min(a[u][v], w);
		myfunc(n, u, v);
		//count the new total distance
		for(i = 1; i < n; i++)
		{
			for(j = 0; j < i; j++)
			{
				tot += a[i][j];
			}
		}
		printf("%d\n", tot);
	}
	return 0;
}
