//
//  14329_LOCKER.cpp
//  
//
//  Created by Haijun Deng on 13-6-12.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 2
 4
 5
 9
 Output:
 4
 6
 27
 */

#include <iostream>
#include <algorithm>

using namespace std;

#define mol 1000000007

long long compute(long long n)
{
    if (n<5) 
        return n;
    else
        return max(compute(n-2)*2,compute(n-3)*3)%mol;
}

int main()
{
    int t;
    long long n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &n);
        printf("%lld\n",compute(n));
    }
    return 0;
}