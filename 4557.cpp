//
//  4557.cpp
//  
//
//  Created by Haijun Deng on 13-1-14.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
4557. Musical Chairs
Input:
5 3
7 1
7 2
7 3 
7 4
7 5
7 6
0 0

Output:
5 3 4
7 1 7
7 2 2
7 3 4
7 4 2
7 5 6
7 6 3 
*/

#include <stdio.h>

int solve(int n, int d)
{
	register int i, a = 0;
	for(i=2; i<=n; i++)
		a = (a+d)%i;
	return a;
}

int main()
{
	int n, d;
	while(scanf("%d%d", &n, &d)==2 && n+d)
		printf("%d %d %d\n", n, d, solve(n, d) + 1);
	return 0;
}
