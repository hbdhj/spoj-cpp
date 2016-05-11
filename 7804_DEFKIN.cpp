//
//  7804_DEFKIN.cpp
//
//
//  Created by Haijun Deng on 13-4-19.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int tn;
    scanf("%d",&tn);
    while(tn--)
    {
        int x,y,n;
        scanf("%d %d %d", &x, &y, &n);
        vector<int> x_l(n+2,0);
        vector<int> y_l(n+2,0);
        for (int i=1; i<=n; i++)
        {
            scanf("%d %d", &x_l[i], &y_l[i]);
        }
        x_l[n+1]=x+1;
        y_l[n+1]=y+1;
        sort(x_l.begin(),x_l.end());
        sort(y_l.begin(),y_l.end());
        int x_max=0;
        int y_max=0;
        for (int i=0; i<=n; i++)
        {
            if(x_max<(x_l[i+1]-x_l[i]-1))
                x_max=x_l[i+1]-x_l[i]-1;
            if(y_max<(y_l[i+1]-y_l[i]-1))
                y_max=y_l[i+1]-y_l[i]-1;
        }
        printf("%d\n", x_max*y_max);
    }
    return 0;
}
