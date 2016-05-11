//
//  15431_UCV2013C.cpp
//
//
//  Created by Haijun Deng on 13-7-25.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Farmer Cream
 1+n(n+1)/2
 Input:
 160 1 70 30
 500 3 50 100
 250000 40 300 5000
 0 0 0 0

 Output:
 The firm is trying to bankrupt Farmer Cream by 10 Bsf.
 Farmer Cream will have 150 Bsf to spend.
 The firm is trying to bankrupt Farmer Cream by 1300 Bsf.
 */
#include <iostream>
int main()
{
    long long d,f,b,m;
    scanf("%lld %lld %lld %lld", &d, &f, &b, &m);
    while (d!=0&&f!=0&&b!=0&&m!=0) {
        long long p=1+f*(f+1)/2;

        if (d>(b*p+m))
            printf("Farmer Cream will have %lld Bsf to spend.\n", d-b*p);
        else
            printf("The firm is trying to bankrupt Farmer Cream by %lld Bsf.\n", b*p+m-d);
        scanf("%lld %lld %lld %lld", &d, &f, &b, &m);
    }
    return 0;
}
