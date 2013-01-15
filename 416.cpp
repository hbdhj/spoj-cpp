//
//  416.cpp
//  
//
//  Created by Haijun Deng on 13-1-15.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void div15(string str)
{
    vector<int> nums(10,0);
    int total;
    for(int i=0;i<str.length();i++)
    {
        nums[str[i]-'0']++;
        total+=str[i]-'0';
    }
    if((nums[5]==0)&&(nums[0]==0))
        printf("impossible\n");
    else
    {
        int i=1;
        int n=nums[i];
        while((total%3)!==0)||(i<10)) {
            printf("%d %d")
            if(n==0)
            {
                i++;
                if(i<10)
                    n=nums[i];
            }
            else
            {
                total-=nums[i];
                n--;
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
        char c[1000];
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