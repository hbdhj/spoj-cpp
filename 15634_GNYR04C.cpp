//
//  15634_GNYR04C.cpp
//  
//
//  Created by Haijun Deng on 13-8-13.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
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
        printf("Data set %d: %d %d %d\n", i+1, n, m, r);
    }
    return 0;
}