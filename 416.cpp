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
4
02041
30
51
155
Output:
4200
30
15
15
*/
#include <iostream>
#include <vector>

using namespace std;

void div15(string str)
{
    /*printf("%s : ", str.c_str());
    if((str[str.length()-1]!='0')||(str[str.length()-1]!='0'))
    {
        printf("impossible\n");
        return;
    }*/
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
        int i=1;
        //int n=nums[i];
        int times=0;
        /*while(((total%3)!=0)&&(i<10)) {
            //times++;
            //if(times>100)
            //    break;
            //printf("%d %d %d\n", total, n, i);
            //if(n==0)
            if(nums[i]==0)
            {
                i++;
            //    if(i<10)
            //        n=nums[i];
            }
            else
            {
                total-=i;
                //n--;
                nums[i]--;
            }
        }*/
        //printf("%d %d %d\n", total, n, i);
        printf("total%3=%d")
        int tail=total%3;
        if(tail)
        {
            while(tail<10)
            {
                if(nums[tail])
                {
                    nums[tail]--;
                    tail=0;
                    break;
                }
                tail+=3;
            }
        }
        if(tail)
            printf("impossible\n");
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
    /*div15("15");
    div15("30");
    div15("51");
    div15("50");
    div15("60");
    div15("02041");*/
    return 0;
}