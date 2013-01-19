//
//  10416.cpp
//  
//
//  Created by Haijun Deng on 13-1-19.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tN,i;
    cin>>tN;
    vector<int> ins(tN);
    for (i=0; i<tN; i++)
        cin>>ins[i];
    for (i=0; i<tN; i++)
        printf("%.4f\n",4.6862915010*ins[i]*ins[i]*ins[i]);
    return 0;
}