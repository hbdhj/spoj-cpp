/*
TASK: Einbahnstrasse
ALGO: warshall
Input:
4 2 5
NewTroy Midvale Metrodale
NewTroy   <-20-> Midvale
Midvale   --50-> Bakerline
NewTroy    <-5-- Bakerline
Metrodale <-30-> NewTroy
Metrodale  --5-> Bakerline
0 0 0

Output:
1. 80
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;

map< string, int > M;
map< string, int >::iterator it;
int grid[100][100];
int broken[1000];

int hash(char *s, int &n) 
{
	int r; 
	it = M.find(s);
	if(it == M.end())
	{ 
		r=n++;
		M.insert(pair< string, int >(s, r));
	}
	else
	{ 
		r = it->second;
	}
	return r;
}

int main() 
{
	int n, c, r, cs = 1, gar, k, i, j, l, w, u, v, tot;
	char name1[32], name2[32], dir[32], temp[32];
	while(scanf("%d %d %d", &n, &c, &r)==3 && n) 
	{
		M.clear(); 
		k = 0; 
		memset(grid, 0x3f, sizeof(grid));
		for(i = 0; i < n; i++) 
		{
			grid[i][i] = 0;
		}
		scanf("%s", name1); 
		gar = hash(name1, k);
		for(i = 0; i < c; i++) 
		{
			scanf("%s", name1);
			broken[i] = hash(name1, k);
		}
		for(i = 0; i < r; i++) 
		{
			scanf("%s %s %s", name1, temp, name2);
			u = hash(name1, k); 
			v = hash(name2, k);
			for(w = j = l = 0; temp[j]; j++) 
			{
				if(isdigit(temp[j])) 
					w = w * 10 + temp[j] - '0';
				else 
					dir[l++] = temp[j];
			}
			if(dir[0] == '<') 
				grid[v][u] = min(w, grid[v][u]);
			if(dir[3] == '>') 
				grid[u][v] = min(w, grid[u][v]);
		}
		for(k = 0; k < n; k++) 
		{
			for(i = 0; i < n; i++) 
			{
				for(j = 0; j < n; j++) 
				{
					grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
				}
			}
		}
		for(tot = i = 0; i < c; i++) 
		{
			tot += grid[gar][broken[i]];
			tot += grid[broken[i]][gar];
		}
		printf("%d. %d\n", cs++, tot);
	}
	return 0;
}
