//
//  15074_Tourney.cpp
//  
//
//  Created by Haijun Deng on 13-6-15.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Tourney
 Input:
 2 8
 30
 20
 10
 40
 S 1
 W
 R 4 9
 S 4
 W
 R 2 35
 S 2
 W
 Output:
 1
 4
 0
 1
 2
 2
 */
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n,m;
    scanf("%d %d", &n,&m);
    //printf("n=%d, m=%d\n",n,m);
    int t_n=1<<n;
    //vector< vector<int> > results;
    vector<int> skill(t_n,0);
    vector<int> result(t_n,0);
    vector<int> round(t_n,0);
    for (int i=0;i<t_n;i++) 
    {
        scanf("%d",&skill[i]);
    }
    //results.push_back(result0);
    int start = 0;
    for (int i=0;i<n;i++) // the round
    {
        int remain=1<<(n-i);
        for (int j=0;j<remain/2;j++) 
        {
            if (start) 
            {
                //printf("L58 skill[%d] = %d, skill[%d]= %d\n",result[start-remain+2*j], skill[result[start-remain+2*j]], result[start-remain+2*j+1], skill[result[start-remain+2*j+1]]);
                if(skill[result[start-remain+2*j]]>skill[result[start-remain+2*j+1]])
                    result[start+j]=result[start-remain+2*j];
                else
                    result[start+j]=result[start-remain+2*j+1];
            }
            else
            {
                //printf("L66 skill[%d] = %d, skill[%d]= %d\n",2*j, skill[2*j], 2*j+1, skill[2*j+1]);
                if(skill[2*j]>skill[2*j+1])
                    result[j]=2*j;
                else
                    result[j]=2*j+1;
            }
        }
        start+=1<<(n-i-1);
        //printf("%d %d\n",remain,start);
    }
    /*for (int i=0;i<t_n-1;i++) // the round
    {
        printf("%d ",result[i]+1);
    }
    printf("\n");*/
    for (int i=0;i<m;i++) // the round
    {
        //printf("%d %d\n",i,m);
        char a;
        int ii,s;
        scanf("%c",&a);
        switch (a) 
        {
            case 'R':
                scanf("%d %d",&ii,&s);
                break;
            case 'W':
                //scanf("%d",&i);
                break;
            case 'S':
                scanf("%d",&ii);
                break;
            default:
                //printf("%c\n",a);
                break;
        }
    }  
    return 0;
}
