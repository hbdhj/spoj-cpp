//
//  15267_FRNDCIRC.cpp
//  
//
//  Created by Haijun Deng on 13-6-26.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: FRIEND CIRCLE
 Input:
 1
 3
 Lucy Patty
 Patty Alice
 Alice Mira
 Output:
2
3
4
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
        map<string, string> unknowns;
        map<string, int>::iterator it_f, it_s;
        circles.clear();
        unknowns.clear();
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
                    map<string, string>::iterator unk_s;
                    unk_s=unknowns.find(second);
                    while(unk_s!=unknowns.end())
                    {
                        circles.insert(pair<string, int>(unk_s->second, 1));
                        unk_s=unknowns.find(unk_s->second);
                    }
                }
                if (it_f==circles.end()&&it_s!=circles.end())
                {
                    circles.insert(pair<string, int>(first, 1));
                    map<string, string>::iterator unk_f;
                    unk_f=unknowns.find(first);
                    while(unk_f!=unknowns.end())
                    {
                        circles.insert(pair<string, int>(unk_f->second, 1));
                        unk_f=unknowns.find(unk_f->second);
                    }
                }
                if(it_f==circles.end()&&it_s==circles.end())
                {
                    map<string, string>::iterator unk_f, unk_s;
                    unk_f=unknowns.find(first);
                    unk_s=unknowns.find(second);
                    if(it_f==circles.end()&&it_s==circles.end())
                    {
                        unknowns.insert(pair<string, string>(first, second));
                        unknowns.insert(pair<string, string>(second, first));
                    }
                }
            }
            else
            {
                circles.insert(pair<string, int>(first, 1));
                circles.insert(pair<string, int>(second, 1));
            }
            printf("%d %d\n", (int)(circles.size()), (int)(unknowns.size()));
        }
    }
    return 0;
}
