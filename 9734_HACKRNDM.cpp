//
//  9734_HACKRNDM.cpp
//
//
//  Created by Haijun Deng on 13-5-17.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 ALGO: sort
 Input:
 5 2
 1 5 3 4 2

 Output:
 3
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,k,i,j;
    cin>>n>>k;
    vector<int> num(n,0);
    for (int i=0; i<n; i++)
    {
        cin>>num[i];
    }
    if(n==1)
        cout<<0<<endl;
    else
    {
        sort(num.begin(), num.end());
        int count=0;
        for (i=0, j=i+1; (i<n-1)&&(j<n); )
        {
            if((num[j]-num[i])>k)
            {
                i++;
            }
            else if((num[j]-num[i])<k)
            {
                j++;
            }
            else
            {
                i++;
                j++;
                count++;
            }
            //cout<<"i = "<<i<<", j = "<<j<<endl;
        }
        cout<<count<<endl;
    }
    return 0;
}
