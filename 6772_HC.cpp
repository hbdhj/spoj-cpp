//
//  6772_HC.cpp
//
//
//  Created by Haijun Deng on 13-3-29.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 ALGO : nim game
 REFER:  http://baike.baidu.com/view/1101962.htm
 Sample Input
 1
 2
 lxh
 hhb

 Sample Output
 lxh
 */
#include <ios>

int main()
{
	int t, n, i, p;
	char name[5], player[2][5] = {"hhb", "lxh"};
	for(scanf("%d", &t); t; t--)
    {
		scanf("%d%s", &n, name);
		p = (name[0]=='l');
		for(i=1; i<n; i++)
        {
			scanf("%s", name);
			p ^= (name[0]=='l');
		}
		puts(player[p]);
	}
	return 0;
}
