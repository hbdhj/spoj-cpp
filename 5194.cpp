//
//  5194.cpp
//  
//
//  Created by Haijun Deng on 13-1-4.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int robbery(unsigned long int n, int k)
{
    if(k==1)
    {
        printf("%lu\n", n);
    }
    else
    {
        int divide=(sqrt(float(n*8+1))-1)/2;
        int remain=n-divide*(divide+1)/2;
        int row=divide/k;
        int last_row=divide%k;
        int i=0;
        for(i=0;i<last_row;i++)
        {
            printf("%d ", (i+1)*(row+1)+k*(row+1)*row/2);
        }
        if(last_row!=(k-1))
        {
            printf("%d ", (i+1)*row+k*(row-1)*row/2+remain);
            for(i=last_row+1;i<k-1;i++)
            {
                printf("%d ", (i+1)*row+k*(row-1)*row/2);
            }
            printf("%d\n",k*row+k*(row-1)*row/2);
        }
        else
        {
            printf("%d\n", (i+1)*row+k*(row-1)*row/2+remain);
        }
    }
    return 0;
}

int main()
{
    int t,k,i;
    unsigned long int n;
    vector<unsigned long int> ns;
    vector<int> ks;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
        scanf("%lu", &n);
        scanf("%d", &k);
        ns.push_back(n);
        ks.push_back(k);
    }
    for(i=0;i<t;i++)
    {
        robbery(ns[i],ks[i]);
    }
    return 0;
}

