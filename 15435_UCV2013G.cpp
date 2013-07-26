//
//  15435_UCV2013G.cpp
//  
//
//  Created by Haijun Deng on 13-7-25.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Schedules
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int na, nb, ts;
    int h, m, s;
    scanf("%d %d %d", &na, &nb, &ts);
    while (na!=0&&nb!=0&&ts!=0) {
        vector<long> la(na, 0);
        vector<long> lb(nb, 0);
        for (int i=0; i<na; i++) {
            scanf("%d:%d:%d", &h, &m, &s);
            la[i]=h*3600+m*60+s;
        }
        for (int i=0; i<nb; i++) {
            scanf("%d:%d:%d", &h, &m, &s);
            lb[i]=h*3600+m*60+s;
        }
        sort(la.begin(), la.end());
        sort(lb.begin(), lb.end());
        int match = 0;
        int total = 0;
        for (int i=0; i<nb; i++) 
        {
            int min = ts+1;
            for (int j=0; j<na; j++) 
            {
                if(la[j]>lb[i]+ts)
                    break;
                else if(la[j]>=lb[i]-ts)
                {
                    if (min>abs(la[j]-lb[i])) {
                        min=abs(la[j]-lb[i]);
                    }
                }
            }
            if(min<=ts)
            {
                total+=min;
                match++;
            }
        }
        if(match)
            printf("%d %.1f\n", match, float(total)/match);
        else
            printf("No matches\n");
        scanf("%d %d %d", &na, &nb, &ts);
    }
    
    return 0;
}
