//
//  8374.cpp
//  
//
//  Created by Haijun Deng on 13-1-13.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 input 
 8 1  
 output 
 3 3
 input 
 10 2 
 output 
 4 3
 */
#include <iostream>
#include <cmath>

int main()
{
    long c1,c2, b, c;
    scanf("%ld %ld",&c1,&c2);
    b=(c1+4)/2;
    c=c1+c2;
    if(b*b-4*c)
    {
        int sq = sqrt(float(b*b-4*c));
        printf("%ld %ld\n", (b+sq)/2, (b-sq)/2);
    }
    else
        printf("%ld %ld\n", b/2, b/2);
    return 0;
}