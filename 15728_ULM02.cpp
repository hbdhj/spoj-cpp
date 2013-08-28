//
//  15728_ULM02.cpp
//  
//
//  Created by Haijun Deng on 13-8-28.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>

void print(int n, int s, int l)
{
    if(n==1)
    {
        //cout<<"  /\\"<<endl<<" /__\\"<<endl;
        printf("  /\\\n /__\\\n");
    }
    else
    {
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n) 
    {
        print(n, 0 ,0);
        scanf("%d", &n);
    }
    return 0;
}