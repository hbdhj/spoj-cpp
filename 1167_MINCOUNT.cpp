//
//  1167.cpp
//  
//
//  Created by Haijun Deng on 13-1-12.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Move To Invert
 100 is 1683 
 10^10 is 7443294631478557525
 */
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

unsigned long long int Invert(unsigned long long int n)
{
    if(n<2)
        return 0;
    else if(n==2)
        return 1;
    else if(n==3)
        return 2;
    else if(n==4)
        return 3;
    else
    {
        /*if(n%2)
        {
            unsigned long long int m=n/2;
            return m*(m-1)+m*(m+1)/2;
        }
        else
        {
            unsigned long long int m=n/2;
            return (m+1)*m/2+(m-1)*(m-2);
        }*/
        unsigned long long int m=(n+2)/3;
        return m*(m-1)+(n-m*2+2)*(n-m*2+1)/2;
    }
}

int main()
{
    int tN,i;
    scanf("%d", &tN);
    vector<unsigned long long int> inputs(tN);
    for (i=0; i<tN; i++) {
        scanf("%llu",&inputs[i]);
    }
    for (i=0; i<tN; i++) {
        printf("%llu\n",Invert(inputs[i]));
    }
    return 0;
}
