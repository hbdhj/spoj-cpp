/*
345. Mixtures
dynamic programming
Input:
2
18 19
3
40 60 20

Output:
342
2400
*/

#include <stdio.h>

const int INF = 0x7f7f7f7f;
const int MAX = 128;

int dp[MAX][MAX], mix[MAX][MAX], color[MAX];

int solve(int s, int e) {
	if(dp[s][e] > -1) 
		return dp[s][e];
	int ret = INF, smoke;
	for(int i = s; i < e; i++) 
	{
		smoke = mix[s][i] * mix[i+1][e];
		smoke += solve(s, i);
		smoke += solve(i+1, e);
		ret = smoke < ret? smoke : ret;
	}
	return dp[s][e] = ret;
}

int main() {
	int n, i, j;
	while(scanf("%d", &n)==1) {
		for(i = 0; i < n; i++) 
			scanf("%d", &color[i]);
		for(i = 0; i < n; i++) 
		{
			mix[i][i] = color[i];
			dp[i][i] = 0;
			for(j = i + 1; j < n; j++) 
			{
				mix[i][j] = mix[i][j-1] + color[j];
				dp[i][j] = -1;
				if(mix[i][j] >= 100) 
					mix[i][j] -= 100;
			}
		}
		printf("%d\n", solve(0, n-1));
	}
	//system("pause");
	return 0;
}