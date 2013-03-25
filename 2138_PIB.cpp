//
//  2138.cpp
//  
//
//  Created by Haijun Deng on 12-12-26.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//
/*
 Input file:
 0
 4
 11
 -1
 
 Output file:
 1
 2
 20
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

unsigned long long int Pibonacci(float n)
{
    if(n<4)
        return 1;
    else
        return Pibonacci(n-1.0)+Pibonacci(n-M_PI);
}

int main()
{
    int n, max;
    scanf("%d", &n);
    vector<int> inputs;
    while(n!=-1)
    {
        if(max<n)
            max=n;
        inputs.push_back(n);
        scanf("%d", &n);
    }
    for(int i=0;i<inputs.size();i++)
        cout<<Pibonacci(inputs[i])<<endl;
    /*for(int i=0;i<200;i++)
    {
        cout<<Pibonacci(i*0.1)<<", ";
        if(i%50==0)
            cout<<endl;
    }*/
    
    return 0;
}