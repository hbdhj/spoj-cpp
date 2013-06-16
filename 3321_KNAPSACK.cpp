//
//  3321_KNAPSACK.cpp
//  
//
//  Created by Haijun Deng on 13-6-16.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: The Knapsack Problem
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int>b)
{
    return (float(a.second)/a.first)>(float(b.second)/b.first);
}
int main()
{
    int s,n;
    vector<pair<int, int> > list;
    scanf("%d %d", &s,&n)
    return 0;
}