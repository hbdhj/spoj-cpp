//
//  1870_ MKLABELS.cpp
//  
//
//  Created by Haijun Deng on 13-3-17.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 2
 3
 4
 5
 0
 
 Output:
 Case 1, N = 2, # of different labelings = 1
 Case 2, N = 3, # of different labelings = 3
 Case 3, N = 4, # of different labelings = 16
 Case 4, N = 5, # of different labelings = 125
 http://oeis.org/A000272
 */

#include <stdio.h>

int ans[] = {0,1,1,3,16,125,1296,16807,262144,4782969,100000000};

int main()
{
	int n, test=1;
	while(scanf("%d", &n)==1 && n)
		printf("Case %d, N = %d, # of different labelings = %d\n",test++,n,ans[n]);
	return 0;
}
