//
//  File.cpp
//
//
//  Created by Haijun Deng on 13-5-19.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
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
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while (n)
    {
        vector<int> ai(n,0), bi(n,0);
        for (int i=0; i<n; i++)
        {
            scanf("%d %d", &ai[i], &bi[i]);
        }
        map<int, int> num;
        int cur=0;
        while (true)
        {
            bool find = false;
            for (int i=0; i<n; i++)
            {
                int check = ai[i]+cur*bi[(i+1)%n];
                //printf("checking %d in map, which size is %d\n", check, num.size());
                if(num.find(check)!=num.end())
                {
                    num[check]++;
                    if(num[check]==n)
                    {
                        find = true;
                    }
                }
                else
                {
                    num.insert(pair<int, int>(check,1));
                }
            }
            if (find)
            {
                printf("%d\n", cur);
                break;
            }
            cur++;
        }
        scanf("%d", &n);
        //printf("n = %d\n", n);
    }
    return 0;
}
