//
//  3377.cpp A Bug’s Life
//
//
//  Created by Haijun Deng on 13-1-9.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 2
 3 3
 1 2
 2 3
 1 3
 4 2
 1 2
 3 4


 Output:
 Scenario #1:
 Suspicious bugs found!
 Scenario #2:
 No suspicious bugs found!
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tN, sn, in, i, j, f, s;
    scanf("%d", &tN);
    vector<int> Outputs(tN, 1);
    for(i=0;i<tN;i++)
    {
        scanf("%d %d", &sn, &in);
        //printf("sn = %d, in = %d",sn,in);
        vector<int> ins(sn,0);
        for(j=0;j<in;j++)
        {
            scanf("%d %d", &f, &s);
            if(Outputs[i])
            {
                if((ins[f-1]==0)&&(ins[s-1]==0))
                {
                    if(f>s)
                    {
                        ins[f-1]=2;
                        ins[s-1]=1;
                    }
                    else
                    {
                        ins[f-1]=1;
                        ins[s-1]=2;
                    }
                }
                else if(ins[f-1]==ins[s-1])
                {
                    Outputs[i]=0;
                }
                else if(ins[f-1]==0)
                {
                    ins[f-1]=3-ins[s-1];
                }
                else if(ins[s-1]==0)
                {
                    ins[s-1]=3-ins[f-1];
                }
            }
            /*for (int k=0; k<sn; k++) {
                printf("%d ",ins[k]);
            }
            printf("Outputs[%d] = %d\n", i, Outputs[i]);*/
        }
    }
    for(i=0;i<tN;i++)
    {
        printf("Scenario #%d:\n",i+1);

        if(Outputs[i])
            printf("No suspicious bugs found!\n");
        else
            printf("Suspicious bugs found!\n");
    }
    return 0;
}
