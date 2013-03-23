//
//  7870_ ADV04J.cpp
//  
//
//  Created by Haijun Deng on 13-3-23.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cmath>
int main()
{
    int n,m;
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&m);
        printf("%d\n", int(ceil(log(double(m)))+1));
    }
}