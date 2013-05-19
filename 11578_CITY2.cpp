//
//  11578_CITY2.cpp
//  
//
//  Created by Haijun Deng on 13-5-19.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

/*
 TASK: A Famous City
 Input:
 3
 1 2 3
 3
 1 2 1
 
 Output:
 Case 1: 3
 Case 2: 2
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n, t=1;
    while(scanf("%d", &n)==1&&n>0)
    {
        vector<int> th(n, 0);
        for (int i=0; i<n; i++)
        {
            scanf("%d", &th[i]);
        }
        /*printf("\n");
        for (int i=0; i<n; i++)
        {
            printf("%d ", th[i]);
        }
        printf("\n");*/
        int r=0;
        stack<int> hs;
        for (int i=0; i<n; i++)
        {
            if (hs.size()>0) 
            {
                //printf("hs.size() = %d\n",hs.size());
                if(th[i]>hs.top())
                {
                    //printf("th[%d] = %d, hs.top() = %d\n",i, th[i] ,hs.top());
                    hs.push(th[i]);
                }
                else
                {
                    while(hs.size()>0)
                    {
                        //printf("th[%d] = %d, hs.top() = %d, hs.size() = %d\n",i, th[i] ,hs.top(),hs.size());
                        if(th[i]<hs.top())
                        {    
                            hs.pop();
                            r++;
                        }
                        else
                        {
                            break;
                        }
                        //printf("r=%d\n", r);
                    }
                    if(hs.size()>0)
                    {
                        if(hs.top()<th[i])
                            hs.push(th[i]);
                    }
                    else
                        hs.push(th[i]);
                }
            }
            else if(th[i])
            {
                hs.push(th[i]);
            }
            if (i==n-1) 
            {
                if(hs.top())
                    r+=hs.size();
                continue;
            }
            
        }    
        printf("Case %d: %d\n",t, r);
        t++;
    }
    return 0;
}