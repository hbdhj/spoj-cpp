//
//  15634_GNYR04C.cpp
//
//
//  Created by Haijun Deng on 13-8-13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Lennys Lucky Lotto Lists
 input

 1
 4 10
 output

 Data set 1: 4 10 4

 1 2 4 8
 1 2 4 9
 1 2 4 10
 1 2 5 10
 */
#include <iostream>

int main()
{
    int t,n,m,r;
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        scanf("%d %d", &n, &m);
        int l=(m-(2<<(n-2)));
        //printf("l = %d\n", l);
        r+=(l+1);
        while (l/2) {
            r+=l/2;
            l=l/2;
            //printf("l = %d\n", l);
        }
        printf("Data set %d: %d %d %d\n", i+1, n, m, r);
    }
    return 0;
}
