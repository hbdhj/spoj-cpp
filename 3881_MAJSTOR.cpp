//
//  3881.cpp
//
//
//  Created by Haijun Deng on 13-3-11.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Majstor
 Input
 5
 SSPPR
 1
 SSPPR

 Output
 5
 10


 Input
 5
 SSPPR
 2
 PPRRS
 RRSSP

 Output
 10
 15


 Input
 4
 SPRS
 4
 RPRP
 SRRR
 SSPR
 PSPS

 Output
 12
 21
 */
#include <stdio.h>
inline int add(char s, char f)
{
	if(s==f)
        return 1;
	else if(s=='R' && f=='S')
        return 2;
	else if(s=='P' && f=='R')
        return 2;
	else if(s=='S' && f=='P')
        return 2;
	else
        return 0;
}
int score(char *sven, char *frnd, int r)
{
	int i, t;
	for(i = t = 0; i < r; i++)
        t += add(sven[i], frnd[i]);
	return t;
}
int main()
{
	char sven[52], cards[] = "RPS", frnd[52][52];
	int n, r, i, j, k, exact = 0, known, mxknown = 0;
	scanf("%d%s%d", &r, sven, &n);
	for(i = 0; i < n; i++)
    {
		scanf("%s", frnd[i]);
		exact += score(sven, frnd[i], r);
	}
	printf("%d\n", exact);
	exact = 0;
	for(i = 0; i < r; i++)
    {
		mxknown = 0;
		for(j = 0; j < 3; j++)
        {
			known = 0;
			for(k = 0; k < n; k++)
            {
				known += add(cards[j], frnd[k][i]);
			}
			if(known > mxknown)
                mxknown = known;
		}
		exact += mxknown;
	}
	printf("%d\n", exact);
	return 0;
}
