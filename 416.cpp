//
//  416.cpp
//  
//
//  Created by Haijun Deng on 13-1-15.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
416. Divisibility by 15
Input:
13
6
17
02041
30
51
155
200
8885 
88850
0
00
000
00004
Output:
impossible
impossible
4200
30
15
15
885 
8880
0
0
0
0
*/
#include <iostream>
#include <vector>

using namespace std;

void div15(string str)
{
    vector<int> nums(10,0);
    int total=0;
    for(int i=0;i<str.length();i++)
    {
        nums[str[i]-'0']++;
        total+=str[i]-'0';
    }
    if((nums[5]==0)&&(nums[0]==0))
    {
        printf("impossible\n");
        return;
    }
    else
    {
        if(nums[0]==0)
            nums[5]--;
        if(total==0)
            printf("0\n");
        else
        {
            int tail=total%3;
            if(tail)
            {
                while(tail<10)
                {
                    if(nums[tail])
                    {
                        nums[tail]--;
                        total-=tail;
                        tail=0;
                        break;
                    }
                    tail+=3;
                }
            }
            if((tail)||(total==0))
            {
                //printf("nums[0] = %d", nums[0]);
                if(nums[0])
                    printf("0\n");
                else
                    printf("impossible\n");
            }
            else    
            {
                for(int i=9;i>0;i--)
                {
                    int n=nums[i];
                    while(n--)
                        printf("%d",i);
                }
                if(nums[0]==0)
                    printf("5\n");
                else
                {
                    int n=nums[0];
                    while(--n)
                        printf("%d",0);
                    printf("0\n");    
                }    
            }
        }
    }
}

int main()
{
    int tN;
    vector<string> inputs;
    scanf("%d", &tN);
    for(int i=0;i<tN;i++)
    {
        char c[1001];
        scanf("%s", c);
        string str=c;
        inputs.push_back(str);
    }
    
    for(int i=0;i<tN;i++)
    {
        div15(inputs[i]);
    }
    return 0;
}