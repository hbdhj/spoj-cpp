//
//  12726_QN01.cpp
//  
//
//  Created by Haijun Deng on 13-6-7.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 XOR -> ^
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m,i,j,l;
    scanf("%d",&n);
    if(n==1)
    {
        scanf("%d",&m);
        printf("%d\n1 1\n",m)
    }    
    else
    {
        vector<int> inputs(n);
        for (i=0; i<n; i++)
        {
            scanf("%d",&inputs[i]);
        }
        int start=end=0;
        int max=inputs[0];
        for (i=0; i<n; i++)
        {
            scanf("%d",&inputs[i]);
        }
    }
    return 0;
}