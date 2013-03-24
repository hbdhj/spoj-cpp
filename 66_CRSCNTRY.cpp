//
//  66_CRSCNTRY.cpp
//  
//
//  Created by Haijun Deng on 13-3-24.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 dynamic programming
 Sample input:
 
 3 
 1 2 3 4 5 6 7 8 9 0 
 1 3 8 2 0 
 2 5 7 8 9 0 
 1 1 1 1 1 1 2 3 0 
 1 3 1 3 5 7 8 9 3 4 0 
 1 2 35 0 
 0 
 1 3 5 7 0 
 3 7 5 1 0 
 0 
 1 2 1 1 0 
 1 1 1 0 
 0 
 
 Sample output:
 
 6 
 2 
 3 
 */
#include <iostream>
#include <algorithm> 
using namespace std;

#define MAX 2002

int cardA[MAX], cardB[MAX], DP[2][MAX];

int lcs(int len1, int len2)
{
	int i, j;
	for(j=0; j<=len2; j++)
		DP[0][j] = 0;
	for(i=1; i<=len1; i++)
		for(j=1; j<=len2; j++)
			if(cardA[i-1]==cardB[j-1])
				DP[i&1][j] = DP[!(i&1)][j-1] + 1;
			else
				DP[i&1][j] = max(DP[!(i&1)][j], DP[i&1][j-1]);
	return DP[len1&1][len2];
}

int main()
{
	int t, len1, len2, n, best;
	scanf("%d", &t);
	while(t--)
	{
		len1 = best = 0;
		while(scanf("%d", &n)==1 && n)
			cardA[len1++] = n;
		while(scanf("%d", &n)==1 && n)
		{
			len2 = 0;
			cardB[len2++] = n;
			while(scanf("%d", &n)==1 && n)
				cardB[len2++] = n;
			best = max(best, lcs(len1, len2));
		}
		printf("%d\n", best);
	}
	return 0;
}