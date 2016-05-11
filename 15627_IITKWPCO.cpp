//
//  15627_IITKWPCO.cpp
//
//
//  Created by Haijun Deng on 13-8-26.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 1000001

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<int> nums(n,0);
        vector<int> number(SIZE, 0);
        for (int i=0; i<n; i++)
        {
            scanf("%d", &nums[i]);
            number[nums[i]]++;
        }
        int group=0;
        for (int i=0; i<n; i++)
        {
            if(nums[i]%2==0)
            {
                if (number[nums[i]/2]&&number[nums[i]])
                {
                    if(number[nums[i]/2]>number[nums[i]])
                    {
                        group+=number[nums[i]];
                        number[nums[i]/2]-=number[nums[i]];
                        number[nums[i]]=0;
                    }
                    else
                    {
                        group+=number[nums[i]];
                        number[nums[i]]-=number[nums[i]/2];
                        number[nums[i]/2]=0;
                    }
                }
            }
            if(2*nums[i]<SIZE)
            {
                if (number[2*nums[i]]&&number[nums[i]])
                {
                    if(number[2*nums[i]]>number[nums[i]])
                    {
                        group+=number[nums[i]];
                        number[2*nums[i]]-=number[nums[i]];
                        number[nums[i]]=0;
                    }
                    else
                    {
                        group+=number[2*nums[i]];
                        number[nums[i]]-=number[2*nums[i]];
                        number[2*nums[i]]=0;
                    }
                }
            }
        }
        printf("%d\n", group);
    }
    return 0;
}
