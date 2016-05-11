//
//  9756.cpp
//
//
//  Created by Haijun Deng on 13-3-13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 2
 0
 900
 8
 1400
 1200
 1000
 800
 600
 400
 200
 0
 0

 Output:
 IMPOSSIBLE
 POSSIBLE
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {
        vector<int> cities(n);
        for (int i=0; i<n; i++)
        {
            scanf("%d",&cities[i]);
        }
        sort(cities.begin(),cities.end());
        bool success=true;
        for (int i=0; i<n-1; i++)
        {
            if((cities[i+1]-cities[i])>200)
            {
                success=false;
                break;
            }
        }
        if((success)&&((1422 - cities[n-1])*2<=200))
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
        scanf("%d",&n);
    }
    return 0;
}
