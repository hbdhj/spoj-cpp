/*
97. Party Schedule
dynamic programming
Sample input:
50 10
12 3
15 8
16 9
16 6
10 2
21 9
18 4
12 4
17 8
18 9 
50 10
13 8
19 10
16 8
12 9
10 2
12 8
13 5
15 5
11 7
16 2
0 0
Sample output:
49 26
48 32
*/
#include <stdio.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXE = 101;
const int MAXW = 505;

int cost, fun, dp[MAXE][MAXW];

int max(int a, int b) { return ((a > b) ? a : b); }

int main() {
	int v, n, w, i, best;
	while(scanf("%d%d", &v, &n)==2) 
	{
		if(!v && !n) break;
		for(i = 1; i <= n; i++) 
		{
			scanf("%d%d", &cost, &fun);
			for(w = 1; w <= v; w++) 
			{
				if(cost > w) 
					dp[i][w] = dp[i-1][w];
				else 
					dp[i][w] = max(dp[i-1][w], dp[i-1][w-cost] + fun);
			}
		}
		for(w = v, best = dp[n][v]; w; w--)
			if(dp[n][w] < best)
				break;
		printf("%d %d\n", w + 1, dp[n][v]);
	}
	return 0;
}