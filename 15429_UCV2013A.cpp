//
//  15429_UCV2013A.cpp
//
//
//  Created by Haijun Deng on 13-7-24.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK:Counting Ids
 (X+X^2+X^3)=(X^4-X)/(X-1)
 (a/b)%m = (a%(m*b))/b
 Input:
 2 3
 128 32
 0 0

 Output:
 14
 792805767
 */
#include <iostream>

#define MOL 1000000007;

int main()
{
    int n,l;
    scanf("%d %d", &n, &l);
    while (n!=0&&l!=0)
    {
        if(n==1)
            printf("%d\n", l);
        else if(l==1)
            printf("%d\n", l);
        else
        {
            long long nl = n;
            for (int i=0; i<l; i++) {
                nl=(nl*n)%1000000007;
            }
            //printf("nl = %lld\n", nl);
            nl=(nl-n)%1000000007;
            printf("%lld\n", (nl%(1000000007*(n-1)))/(n-1));
        }
        scanf("%d %d", &n, &l);
    }
    return 0;
}
