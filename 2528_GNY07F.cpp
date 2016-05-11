//
//  2528_GNY07F.cpp
//
//
//  Created by Haijun Deng on 13-4-21.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: 2528. Monkey Vines
Input:
3
[]

[[][[]]]

Output:
1 2
2 1
3 8

 */
#include <cstdio>
#include <stdlib.h>
int main()
{
	char str[200];
	int t = atoi(gets(str)), i, n, x, m;
	for(x=1; x<=t; x++)
	{
		gets(str);
		for(i=n=m=0; str[i]; i++)
		{
			if(str[i]=='[')
                n++;
			else if(str[i]==']')
                n--;
			if(n > m)
                m = n;
		}
		printf("%d %d\n", x, (1<<m));
	}
	return 0;
}
