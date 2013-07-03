//
//  12365_TAP2012B.cpp
//  
//
//  Created by Haijun Deng on 13-7-3.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Ball of Reconciliation
 ALGO: ad-hoc
 Input:
 20
 1
 9747
 -1
 
 Output:
 5
 1
 57
 */
#include <iostream>

int main()
{
    int a[10001];
    memset(a, 0, sizeof(a));
    for (int i=1; i<10000; i++) 
    {
        int j_l = 10000/i;
        for (int j=2; j<j_l; j++)
        {
            int k_l =(10000-i*j)/(i+j);
            for (int k=0; k<k_l; k++)
            {
                a[i*j+j*k+i*k]++;
            }
        }
    }
    int n;
    scanf("%d", &n);
    while (n!=-1)
    {
        printf("%d\n", a[n]);
        scanf("%d", &n);
    }
    return 0;
}
