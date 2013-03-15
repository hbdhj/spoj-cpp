//
//  2530_ GNY07H.cpp
//  
//
//  Created by Haijun Deng on 13-3-15.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 a(n) = a(n-1)+5*a(n-2)+a(n-3)-a(n-4)
 Input:
 3
 2
 3
 7
 
 Output:
 1 5
 2 11
 3 781
 
 4 36 
 5 95 
 6 281 
 7 781 
 */

#include <cstdio>
#include <cstring>
using namespace std;

int dp[4][52][16];

int solve(int r, int c, int mask) 
{
	if(r > 4) 
        return 0;
	if(c < 0) 
        return mask==0;
	if(r == 4) 
        return solve(0, c - 1, mask);
	int &ret = dp[r][c][mask];
	if(ret != -1) 
        return ret;
	ret = 0;
	if(mask & (1 << r)) 
        ret += solve(r + 1, c, mask & ~(1 << r));
	else 
    {
		ret += solve(r + 1, c, mask | (1 << r));
		if(!(mask & (1 << (r + 1)))) 
            ret += solve(r + 2, c, mask);
	}
	return ret;
}

int main() 
{
	int test, cs = 1, n;
	memset(dp, -1, sizeof dp);
	scanf("%d", &test);
	while(test--) 
    {
		scanf("%d", &n);
		printf("%d %d\n", cs++, solve(0, n-1, 0));
	}
	return 0;
}