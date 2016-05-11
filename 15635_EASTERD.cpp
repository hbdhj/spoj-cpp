//
//  15635_EASTERD.cpp
//
//
//  Created by Haijun Deng on 13-8-14.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Easter festival date
 Input:
 2012

 Output:
 2012: 8 April

 http://baike.baidu.com/view/1462.htm
 */
#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int main()
{
    string month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char c[6];
    while(scanf("%s",c)!=EOF)
    {
        int y;
        sscanf(c, "%d", &y);
        int n = y-1900;
        int a = n%19;
        int q = floor(float(n)/4);
        int b = floor((7*float(a)+1.0)/19);
        int m = (11*a+4-b)%29;
        int w = (n+q+31-m)%7;
        int d = 25-m-w;
        if (d>0)
        {
            m=4;
        }
        else
        {
            m=3;
            d+=31;
        }
        printf("%d: %d %s\n",y, d, month[m-1]);
    }
    return 0;
}
