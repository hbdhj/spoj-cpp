//
//  15376_ RMID.cpp
//  
//
//  Created by Haijun Deng on 13-7-13.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Running Median
 Input:
 1
 2
 3
 4
 -1
 -1
 5
 6
 7
 -1
 0
 
 2
 3
 -1
 0
 
 Output:
 2
 3
 5
 
 2
 */
#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l;
    list<int>::iterator median=l.begin();
    list<int>::iterator todelete;
    int n;
    while (scanf("%d", &n)==1)
    {
        while (n!=0) 
        {
            if (n>0) 
            {
                l.push_back(n);
                if(l.size()%2)
                    median++;
            }
            else if(n==-1)
            {
                printf("%d\n", *median);
                todelete = median;
                if(l.size()%2)
                    median--;
                else
                    median++;
                l.erase(todelete);
            }
            scanf("%d", &n);
        }
        printf("\n");
    }
    return 0;
}
