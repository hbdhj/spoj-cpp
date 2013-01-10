//
//  2127.cpp
//  
//
//  Created by Haijun Deng on 13-1-10.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*s[i] = (78901 + 31*s[i-1]) mod  699037
t[i] = (23456 + 64*t[i-1]) mod 2097151
The output of the i-th step is the number

a[i]=(s[i] mod 100 + 1) * (t[i] mod 100 + 1)
 Input file:
 1
 123456 123456 10 10000
 
 Output file:
 2
*/
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int i, j, n, s0, t0, ai, N, M;
    scanf("%d", &n);
    vector<int> inputs(n*4);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d", &s0, &t0, &N, &M);
        inputs[i*4]=s0;
        inputs[i*4+1]=t0;
        inputs[i*4+2]=N;
        inputs[i*4+3]=M;
    }
    for(i=0;i<n;i++)
    {
        s0=inputs[i*4];
        t0=inputs[i*4+1];
        N=inputs[i*4+2];
        M=inputs[i*4+3];
        list<int> que;
        int sum=0;
        int max=100000;
        bool meet=false;
        for(j=0;j<N;j++)
        {
            meet=false;
            s0=(78901 + 31*s0)%699037;
            t0=(23456 + 64*t0)%2097151;
            ai=(s0%100+1)*(t0%100+1);
            que.push_back(ai);
            sum+=ai;
            //printf("ai = %d, sum = %d, max = %d\n",ai, sum, max);
            while(sum>M)
            {
                meet=true;
                sum-=que.front();
                que.pop_front();
            }
            if(meet&&max>que.size())
                max=que.size();
        }
        printf("%d\n", max);
    }    
    return 0;
}
