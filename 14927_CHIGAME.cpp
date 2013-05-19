//
//  File.cpp
//  
//
//  Created by Haijun Deng on 13-5-19.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Chinese game
 ALGO: map
 Input:
 3
 15 5
 17 8
 16 7
 2
 1 2
 1 3
 0
 
 Output:
 3
 0
 17	16	15
 24	21	23
 31	26	31
 38	31	39
 */

#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while (n) 
    {
        vector<int> ai, bi;
        for (int i=0; i<n; i++) 
        {
            scanf("%d %d", &ai[i], &bi[i]);
        }
        
        scanf("%d", &n);
    }
}