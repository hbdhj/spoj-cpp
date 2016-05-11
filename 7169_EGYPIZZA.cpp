//
//  7169.cpp
//
//
//  Created by Haijun Deng on 13-1-12.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 3
 1/2
 3/4
 3/4
 Output:
 4

 Input:
 5
 1/2
 3/4
 1/2
 1/4
 1/4

 Output:
 4
*/
#include <stdio.h>
#include <math.h>

int main()
{
    int i, friend_number, molecular, denominator;
    scanf("%d", &friend_number);
    int half=0;
    int quater=0;
    int threequater=0;
    for(i=0;i<friend_number;i++)
    {
        scanf("%d/%d", &molecular, &denominator);
        if((molecular+denominator)==3)
            half++;
        else if((molecular+denominator)==5)
            quater++;
        else if((molecular+denominator)==7)
            threequater++;
    }
    int pies=1;
    if(threequater<=quater)
    {
        pies+=threequater;
        quater-=threequater;
        pies+=ceil(float(half)/2+float(quater)/4);
        /*quater-=threequater;
        if(half<=quater/2)
        {
            pies+=half;
            quater-=half*2;
            pies+=ceil(float(quater)/4);
        }
        else
        {
            pies+=half;
            half-=ceil(float(quater)/2);
            pies+=ceil(float(half)/2);
        }*/

    }
    else
    {
        pies+=threequater;
        pies+=ceil(float(half)/2);
    }
    printf("%d\n", pies);
}
