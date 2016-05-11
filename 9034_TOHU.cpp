//
//  9034.cpp
//  CPPEditor
//
//  Created by Haijun Deng on 12-12-26.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tN, n, i, j;
    scanf("%d", &tN);
    vector<int> inputs;
    for(i=0;i<tN;i++)
    {
        scanf("%d",&n);
        inputs.push_back(n);
    }
    for(i=0;i<tN;i++)
    {
        double ret=2.0/3+(1.0/6-1.0/(inputs[i]+1)/(inputs[i]+2))/2;
        printf("%.11f\n",ret);
    }
    return 0;
}
