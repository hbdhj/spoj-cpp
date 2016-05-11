//
//  15437_ UCV2013I.cpp
//
//
//  Created by Haijun Deng on 13-7-25.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <math.h>

int main()
{
    int r, n;
    scanf("%d %d", &r, &n);
    while (r!=0&&n!=0) {
        printf("%.2f\n", float(r)/sin(2*M_PI/4/n));
        scanf("%d %d", &r, &n);
    }
    return 0;
}
