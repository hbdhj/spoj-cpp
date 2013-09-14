//
//  15980_ASCDFIB.cpp
//  
//
//  Created by Haijun Deng on 13-9-14.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 
 */
#include <iostream>

int main()
{
    int t, i, j, a, b, n;
    int list[1100001];
    int ret[100001];
    list[0]=0;
    list[1]=1;
    for (int i=2; i<110001; i++) 
    {
        list[i]=(list[i-2]+list[i-1])%100000;
    }
    scanf("%d", &t);
    for (int i=0; i<t; i++) 
    {
    
        scanf("%d %d", &a, &b);
        memset(ret, 0, sizeof(ret));
        for (j = a-1; j<a+b; j++)
        {
            ret[list[j]]++;
        }
        printf("Case %d:", i+1);
        
        for (j = 0, n = 0; j<100000&&n<=(100<b?100:b); j++)
        {
            while (ret[j]--) 
            {
                printf(" %d", j);
                n++;
            }
        }
        printf("\n");
    }
    return 0;
}