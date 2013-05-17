//
//  8493_COLORF.cpp
//  
//
//  Created by Haijun Deng on 13-5-17.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> color_num(n,0);
        int sum=0;
        for (int i=0; i<n; i++)
        {
            cin>>color_num[i];
            sum+=color_num[i];
        }
        int p=1;
        while (sum>1)
        {
            p*=sum;
            sum--;
        }
        for (int i=0; i<n; i++) 
        {
            while(color_num[i]>1)
            {
                p=p/color_num[i];
                color_num[i]--;
            }
        }
        cout<<p<<endl;
    }
    return 0;
}