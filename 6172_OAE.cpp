//
//  6172_OAE.cpp
//
//
//  Created by Haijun Deng on 13-4-20.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tn;
    scanf("%d",&tn);
    vector<int> inputs(tn,0);
    int max=2;
    for (int i=0;i<tn;i++)
    {
        scanf("%d", &inputs[i]);
        if (max<inputs[i])
        {
            max=inputs[i];
        }
    }
    vector<int> n_l(max, 0);
    n_l[0]=9;
    n_l[1]=82;
    for(int i=2;i<max;i++)
    {
        n_l[i]=(n_l[i-1]*n_l[i-2])%314159;
    }
    for(int i=0;i<tn;i++)
    {
        printf("%d\n", n_l[inputs[i]-1]);
    }
    return 0;
}
