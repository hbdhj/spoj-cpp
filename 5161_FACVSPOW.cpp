//
//  5161_FACVSPOW.cpp
//  
//
//  Created by Haijun Deng on 13-6-7.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define LG_SIZE 100000

int main()
{
    int n,m,i;
    vector<float> lg(LG_SIZE);
    lg.push_back(0.0);
    for (int i=2; i<LG_SIZE; i++) 
    {
        lg.push_back((log(float(i))+(i-1)*lg[i-2])/i);
    }
    /*for (int i=0; i<20; i++) 
        printf("%.2f ", lg[i]);
    printf("\n");
    for (int i=0; i<20; i++) 
        printf("%.2f ", log(float(i+1)));
    printf("\n");*/
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &m);
        for (i=0; i<LG_SIZE; i++)
        {
            if(lg[i]>log(float(m)))
            {
                break;
            }
        }
        printf("%d\n", i+1);
    }
    return 0;
}