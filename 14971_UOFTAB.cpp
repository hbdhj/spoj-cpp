//
//  14971_UOFTAB.cpp
//
//
//  Created by Haijun Deng on 13-5-21.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

/*
 TASK: The Foxens Treasure
 ALGO: LCD
 Input:
 2
 2
 2 1 2
 2 2 1
 3
 1 1 0
 1 1 0
 1 1 1
 2
 2 1 2
 2 2 2

 Output:
 6
 Foxen are too powerful
 0
*/

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if(!b)
        return a;
    else
        return gcd(b,a%b);
}

int lcd(int a, int b)
{
    return a*b/gcd(a, b);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<int> Ai(n,0), Si(n,0), Oi(n,0);
        for (int i=0; i<n; i++)
        {
            scanf("%d %d %d", &Ai[i], &Si[i], &Oi[i]);
        }
        int ret=Ai[0]+Si[0];
        for (int i=1; i<n; i++)
        {
            ret=lcd(ret, Ai[i]+Si[i]);
        }
        //printf("ret = %d\n", ret);
        vector<int> status(ret, 0);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<ret; j++)
            {
                int l=(j+Oi[i])%(Ai[i]+Si[i]);
                if(l<Ai[i])
                    status[j]=1;
            }
        }
        int succ = -1;
        for (int j=0; j<ret; j++)
        {
            //printf("%d ", status[j]);
            if(status[j]==0)
            {
                succ = j;
                break;
            }
        }
        if (succ>=0)
        {
            printf("%d\n", succ);
        }
        else
        {
            printf("Foxen are too powerful\n");
        }

    }
    return 0;
}
