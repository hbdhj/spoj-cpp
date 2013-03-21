//
//  3979_MZVRK.cpp
//  
//
//  Created by Haijun Deng on 13-3-21.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
long long whirligig(long long n)
{
    vector<int> digits;
    while (n) {
        digits.push_back(n%2);
        n=n/2;
    }
    long long ret=1;
    for(int i=0;i<digits.size();i++)
    {
        if (digits[i]==1) {
            break;
        }
        ret*=2;
    }
    return ret;
}

int main()
{
    //cout<<"whirligig(176)="<<whirligig(176)<<endl;
    //cout<<"whirligig(177)="<<whirligig(177)<<endl;
    long long m,n;
    cin>>m>>n;
    cout<<whirligig(m)+whirligig(n)<<endl;
    return 0;
}