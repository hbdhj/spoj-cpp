//
//  11032_MAXINARR.cpp
//
//
//  Created by Haijun Deng on 13-6-13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Maximum element of an array
 Input:
 4
 1 2 3 4
 2
 -1 0
 3
 -1000000000 0 1000000000
 0

 Output:
 4
 0
 1000000000
 */
#include <iostream>
using namespace std;

int main()
{
    long long N,max;
    long long * A;
    cin>>N;
    while(N!=0)
    {
        A=new long long[N];
        max=-1000000000;
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
            if(A[i]>max)
                max=A[i];
        }
        cout<<max<<endl;
        delete[] A;
        cin>>N;
    }
    return 0;
}
