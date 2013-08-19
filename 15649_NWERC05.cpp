//
//  15649_NWERC05.cpp
//  
//
//  Created by Haijun Deng on 13-8-19.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Unequalled Consumption
 ntput
 
 3
 5 5 10
 1
 4
 4
 3 1 4 2
 2
 142 700
 1
 10
 1
 100
 0
 output
 
 Set 1
 10
 Set 2
 23
 42
 Set 3
 no candy for you
 */
#include <iostream>

int main()
{
    int n, w[5], q, i, j, t;
    long long p[10];
    scanf("%d", &n);
    t=1;
    while (n)
    {
        for (i=0; i<n; i++) 
        {
            scanf("%d", &w[i]);
        }
        scanf("%d", &q);
        for (i=0; i<q; i++) 
        {
            scanf("%lld", &p[i]);
        }
        printf("Set %d\n", t++);
        scanf("%d", &n);
    }
    return 0;
}