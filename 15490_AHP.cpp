//
//  15490_AHP.cpp
//  
//
//  Created by Haijun Deng on 13-7-28.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: After Hard Party
 Input: 
 3
 ||||||000|||||\0/0000|0|0000/0/||0|0|0|0
 ||||/0|||||
 /0//0|0|\0\\
 
 Output:
 5
 That Bad Party xD
 3
 */

#include <iostream>

#define MAX 100001

char friends[MAX];

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) 
    {
        memset(friends, 0, sizeof(friends));
        scanf("%s", friends);
        //printf("friends=%s\n", friends);
        int cur=0;
        int count=0;
        while (friends[cur]) 
        {
            //printf("%c ", friends[cur]);
            if(cur>1)
            {
                if( (('\\'==friends[cur-2])&&('\\'==friends[cur]))
                   ||(('/'==friends[cur-2])&&('/'==friends[cur]))
                   ||(('\\'==friends[cur-2])&&('/'==friends[cur]))
                   ||(('|'==friends[cur-2])&&('|'==friends[cur]))
                   &&('0'==friends[cur-1]))
                {
                    count++;
                    cur+=2;
                }
            }
            cur++;
        }
        if (count)
        {
            printf("%d\n", count);
        }
        else
        {
            printf("That Bad Party xD\n");
        }
    }
    return 0;
}