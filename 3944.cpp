//
//  3944.cpp
//  SPOJ
//
//  Created by Haijun Deng on 12-12-28.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//
/*
  (108*n+72+36*n^2)*a(n)+(24*n^2+96*n+96)*a(n+1)+(n^2+5*n+6)*a(n+2)+(-6*n-9-n^2)*a(n+3)=0
 */
#include <iostream>
#include <vector>

using namespace std;

unsigned long long int beeMove(int n)
{
    unsigned long long int ret;
    switch (n) {
        case 0:
            ret = 1;
            break;
            
        case 1:
            ret = 0;
            break;
            
        case 2:
            ret = 6;
            break;
            
        case 3:
            ret = 12;
            break;
            
        case 4:
            ret = 90;
            break;
            
        case 5:
            ret = 360;
            break;
            
        default:
            int m = n-3;
            ret = ((108*m+72+36*m*m)*beeMove(m)+(24*m*m+96*m+96)*beeMove(m+1)+(m*m+5*m+6)*beeMove(m+2))/(6*m+9+m*m);
            break;
    }
    return ret;
}

int main()
{
    int tN,i,n;
    vector<int> inputs;
    cin>>tN;
    for(i=0;i<tN;i++)
    {
        cin>>n;
        inputs.push_back(n);
    }
    for(i=0;i<tN;i++)
        cout<<beeMove(inputs[i])<<endl;
    return 0;
}
