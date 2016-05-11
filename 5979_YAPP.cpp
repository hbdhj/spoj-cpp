//
//  5979.cpp
//
//
//  Created by Haijun Deng on 12-12-31.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

unsigned long long int Permu(unsigned long long int n)
{
    unsigned long long int ret=1;
    for(unsigned long long int i =0;i<(n-1)/20;i++)
    {
        ret*=1048576;
        if(ret>MOD)
            ret=ret%MOD;
    }
    for(unsigned long long int i =0;i<(n-1)%20;i++)
    {
        ret*=2;
        if(ret>MOD)
            ret=ret%MOD;
    }
    return ret;
}

int main()
{
    int tN,i;
    scanf("%d", &tN);
    vector<unsigned long long int> inputs;
    for(i=0;i<tN;i++)
    {
        unsigned long long int n;
        scanf("%llu",&n);
        inputs.push_back(n);
    }
    for(i=0;i<tN;i++)
    {
        printf("%llu\n", Permu(inputs[i]));
    }
}
