//
//  15965_ENIGMATH.cpp
//  
//
//  Created by Haijun Deng on 13-9-16.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: PLAY WITH MATH
 Input :
 1
 2 3 
 
 Ouput :
 3 2 
 */
#include <iostream>

long long gcd(long long a, long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{
    int t;
    long long a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld", &a, &b);
        c=gcd(a, b);
        printf("%lld %lld\n", b/c, a/c);
    }
    return 0;
}