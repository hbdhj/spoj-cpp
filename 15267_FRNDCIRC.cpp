//
//  15267_FRNDCIRC.cpp
//  
//
//  Created by Haijun Deng on 13-6-26.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 1
 3
 Lucy Patty
 Patty Alice
 Alice Mira
 */
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) 
    {
        map<string, int> circles;
        map<string, int>::iterator it_f, it_s;
        circles.clear();
        int n;
        scanf("%d", &n);
        for (int i=0; i<n; i++)
        {
            char first[22], second[22];
            scanf("%s %s", first, second);
            it_f=circles.find(first);
            it_s=circles.find(second);
            if (i) 
            {
                if (it_f!=circles.end()&&it_s==circles.end()) 
                {
                    circles.insert(pair<string, int>(second, 1));
                }
                if (it_f==circles.end()&&it_s!=circles.end())
                {
                    circles.insert(pair<string, int>(first, 1));
                }
                if(it_f==circles.end()&&it_s==circles.end())
                {
                }
            }
            else
            {
                circles.insert(pair<string, int>(first, 1));
                circles.insert(pair<string, int>(second, 1));
            }
            printf("%d\n", circles.size());
        }
    }
    return 0;
}