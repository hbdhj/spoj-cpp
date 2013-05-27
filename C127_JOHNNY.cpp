//
//  C127_ JOHNNY.cpp
//  
//
//  Created by Haijun Deng on 13-5-27.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second>b.second;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > nums;
    for (int i=0; i<n; i++) 
    {
        int num;
        scanf("%d", &num);
        nums.push_back(pair<int, int>(i+1, num));
    }
    sort(nums.begin(), nums.end(), comp);
    int left=0,right=0;
    vector<int> lefts;
    for(int i=0; i<n; i++)
    {
        //printf("%d th num is %d after sorting\n", nums[i].first, nums[i].second);
        if(left<right)
        {
            left+=nums[i].second;
            lefts.push_back(nums[i].first);
        }
        else
            right+=nums[i].second;
    }
    sort(lefts.begin(), lefts.end());
    for(int i=0; i<lefts.size(); i++)
    {
        printf("%d\n", lefts[i]);
    }
    return 0;
}