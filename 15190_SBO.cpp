//
//  15190_SBO.cpp
//
//
//  Created by Haijun Deng on 13-6-11.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: MAXIMUM RARITY
 Input 1:
 7
 1 1 2 5 1 16 5
 Output 1:
 4

 Input 2:
 3
 1 2 3
 Output 2:
 3

 Input 3:
 10
 2 1 4 1 5 6 7 1 8 2
 Output 3:
 6
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> input(n,0);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
    }
    int max=1;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            vector<int> rare;
            for (int l=i; l<=j; l++)
            {
                vector<int>::iterator it = find (rare.begin(), rare.end(), input[l]);
                if(it!=rare.end()) //repeat
                {
                    break;
                }
                else
                {
                    rare.push_back(input[l]);
                    if (max<(l-i+1))
                    {
                        max=l-i+1;
                    }
                }
            }
            //printf("i = %d, j = %d, max=%d\n", i, j, max);
        }
    }
    printf("%d\n", max);
    return 0;
}
