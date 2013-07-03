//
//  15241_VPL2_AA.cpp
//  
//
//  Created by Haijun Deng on 13-7-3.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Luis Quest
 ALGO: math
 INPUT
 4
 10 15 3 15
 10 15 3 20
 5 12 2 50
 5 12 2 7
 
 OUTPUT
 Scenario #1: 3.00
 Scenario #2: 5.13
 Scenario #3: 5.26
 Scenario #4: 0.77
 */
#include <iostream>
#include <math.h>

int main()
{
    int tN, p0,p1,t,p;
    scanf("%d", &tN);
    for (int i=0; i<tN; i++)
    {
        scanf("%d %d %d %d", &p0, &p1, &t, &p);
        printf("Scenario #%d: %.2f\n", i+1, (log(float(p))-log(float(p0)))*t/(log(float(p1))-log(float(p0))));
    }
    return 0;
}
