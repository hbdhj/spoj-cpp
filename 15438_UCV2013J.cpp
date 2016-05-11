//
//  15438_UCV2013J.cpp
//
//
//  Created by Haijun Deng on 13-7-24.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Valences
 sum of the leave node of a binary trees
 1 5
 2 1 2
 3 1 2 3
 4 1 2 3 4
 5 1 2 3 4 5
 6 1 2 3 4 5 6
 7 1 2 3 4 5 6 7
 8 1 2 3 4 5 6 7 8
 9 1 2 3 4 5 6 7 8 9
 10 1 2 3 4 5 6 7 8 9 10
 0
 5
 2
 5
 7
 12
 15
 22
 26
 35
 40
 */
#include <iostream>
#include <math.h>

int main()
{
    int n, c, s, t, i, l;
    scanf("%d", &n);
    while (n!=0)
    {
        s=1;
        while (s-1<n) {

            s*=2;
        }
        s/=2;
        s--;
        s-=(s/2-(n-s-1)/2);
        for (i=0; i<s; i++) {
            scanf("%d", &c);
        }
        t=0;
        for (i=s; i<n; i++) {
            scanf("%d", &c);
            t+=c;
        }
        printf("%d\n",t);
        scanf("%d", &n);
    }
    return 0;
}
