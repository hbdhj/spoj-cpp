//
//  1716_GSS3.cpp
//  
//
//  Created by Haijun Deng on 13-5-17.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 ALGO: segment tree
 Input:
 4
 1 2 3 4
 4
 1 1 3
 0 3 -3
 1 2 4
 1 3 3
 
 Output:
 6
 4
 -3
 */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> inputs(n,0);
    for(int i=0;i<n;i++)
        cin>>inputs[i];
    int m;
    cin>>m;
    while (m--) {
        int o, x, y, result;
        cin>>o>>x>>y;
        //cout<<"x = "<<x<<", y = "<<y<<endl;
        if(o)
        {
            if(x==y)
                cout<<inputs[x-1]<<endl;
            else
            {
                int max=-50000;
                int i, s, j;
                for(i=1;i<=(y-x)+1;i++)
                {
                    for (s=x-1; s<=y-i; s++) 
                    {
                        result=0;
                        for(j=s-1;j<=s-1+i;j++)
                        {
                            result+=inputs[j];
                        }
                        //cout<<"i = "<<i<<", j = "<<j<<", s = "<<s<<", result = "<<result<<", max = "<<max<<endl;
                        if(result>max)
                            max=result;
                    }
                }
                cout<<max<<endl;
            }
        }
        else
            inputs[x-1]=y;
    }
    return 0;
}

