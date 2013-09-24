//
//  16034_MINNUM.cpp
//  
//
//  Created by Haijun Deng on 13-9-24.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>

int main()
{
    long long n;
    scanf("%lld", &n);
    while (n!=-1) 
    {
        if(n<10)
            printf("1\n");
        else if(n%9)
            printf("%lld\n", n/9+1);
        else
            printf("%lld\n", n/9);
        scanf("%lld", &n);
    }
    return 0;
}