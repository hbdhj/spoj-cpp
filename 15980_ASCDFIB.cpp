//
//  15980_ASCDFIB.cpp
//  
//
//  Created by Haijun Deng on 13-9-14.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Ascending Fibonacci Numbers 
 Input:
3
1 3
3 3
100 1

Output:

Case 1: 0 1 1 2
Case 2: 1 2 3 5
Case 3: 15075 69026 
*/
#include <iostream>
#include <string.h>

int main()
{
    int t, i, j, a, b, n;
    int list[1100001];
    int ret[100001];
    list[0]=0;
    list[1]=1;
    for (int i=2; i<1100001; i++) 
    {
        list[i]=(list[i-2]+list[i-1])%100000;
    }
    scanf("%d", &t);
    for (int i=0; i<t; i++) 
    {
    
        scanf("%d %d", &a, &b);
        //printf("%d %d\n",a, b);
        memset(ret, 0, sizeof(ret));
        for (j = a-1; j<a+b; j++)
        {
            ret[list[j]]++;
        }
        printf("Case %d:", i+1);
        int num=100<b?100:b;
        //printf("num = %d\n", num);
        for (j = 0, n = 0; j<100000&&n<=num; j++)
        {
            while (ret[j]--) 
            {
                printf(" %d", j);
                n++;
                if(n==num)
                    break;
                //printf(" n=%d\n", n);
            }
            if(n>=num)
                break;
        }
        printf("\n");
    }
    return 0;
}
