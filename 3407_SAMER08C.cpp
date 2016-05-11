//
//  3407_SAMER08C.cpp
//
//
//  Created by Haijun Deng on 13-5-24.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

/*
 TASK: Candy
 ALGO: dynamic programming
 Input:

 5 5
 1 8 2 1 9
 1 7 3 5 2
 1 2 10 3 10
 8 4 7 9 1
 7 1 3 1 6
 4 4
 10 1 1 10
 1 1 1 1
 1 1 1 1
 10 1 1 10
 2 4
 9 10 2 7
 5 1 1 5
 0 0

 Output:
 54
 40
 17
 */

#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAX 100001

using namespace std;

int dp[MAX], col[MAX], row[MAX], r, c;

int solve(int i, int n, int *a)
{
	if(i >= n)
        return 0;
	if(dp[i])
        return dp[i];
	return dp[i] = max(a[i]+solve(i+2,n,a), solve(i+1,n,a));
}

int main()
{
	int i, j;
	while(scanf("%d%d", &r, &c)==2 && (r || c))
	{
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
                scanf("%d", &row[j]);
			fill(dp, dp+c, 0);
			col[i] = solve(0, c, row);
		}
		fill(dp, dp+r, 0);
		printf("%d\n", solve(0,r,col));
	}
	return 0;
}
