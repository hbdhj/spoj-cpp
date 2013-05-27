//
//  File.cpp
//  
//
//  Created by Haijun Deng on 13-5-27.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
int main()
{
    int a,b,c,i=3;
    char op;
    while (i--) {
        scanf("%d%c%d",&a,&op,&b);
        if (op=='+') c=a+b;
        if (op=='-') c=a-b;
        if (op=='*') c=a*b;
        printf("%d\n",c);
    }
}
