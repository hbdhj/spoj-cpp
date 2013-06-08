//
//  10401_ALIEN.cpp
//  
//
//  Created by Haijun Deng on 13-6-8.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 INPUT:
 4
 5 100
 20 15 30 80 100
 1 50 
 100 
 4 20 
 16 8 16 8 
 4 10 
 2 2 2 4 

 
 OUTPUT
 65 3
 0 0
 8 1
 10 4 
 */
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int A,B,i,ai;
        queue<int> aiq;
        int total=0;
        int max_total=0;
        int length=0;
        int max_length=0;
        scanf("%d %d", &A, &B);
        while (A--)
        {
            scanf("%d", &ai);
            if ((total+ai)<=B)
            {
                aiq.push(ai);
                total+=ai;
                length++;
                if(max_length<length)
                {
                    max_length=length;
                    max_total=total;
                }    
            }
            else
            {
                aiq.push(ai);
                total+=ai;
                length++;
                while (total>B) 
                {
                    total-=aiq.front();
                    aiq.pop();
                }
            }
            //printf("%d %d %d %d\n",length, max_length, total, max_total);
        }
        printf("%d %d\n",max_total, max_length);
    }
    return 0;
}