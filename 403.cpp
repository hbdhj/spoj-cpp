//
//  403.cpp
//  CPPEditor
//
//  Created by Haijun Deng on 12-12-25.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int tN,i,j,n,q,qn;
    scanf("%d",&tN);
    vector<int> inputs;
    vector<vector<int> > querys;
    for(i=0;i<tN;i++)
    {
        scanf("%d",&n);
        inputs.push_back(n);
        scanf("%d",&qn);
        vector<int> query;
        for(j=0;j<qn;j++)
        {
            scanf("%d",&q);
            query.push_back(q);
        }
        querys.push_back(query);
    }
    for(i=0;i<tN;i++)
    {
        vector<pair<int, int> > seq;
        int n=inputs[i];
        //seq.push_back(pair<int, int>(1,n));
        int l=1;
        int m=n;
        while(2*l<m)
        {
            seq.push_back(pair<int, int>(l,m));
            //cout<<l<<"/"<<m<<endl;
            float f1,f2,f3;
            f1=float(l+1)/n;
            f2=float(l+1)/m;
            f3=float(l)/(m-1);
            //printf("%.2f, %.2f, %.2f\n",f1,f2,f3);
            if((f1<f2)&&(f1<f3))
            {
                l++;
                m=n;
            }
            else if((f2<f1)&&(f2<f3))
                l++;
            else if((f3<f2)&&(f3<f1))
                m--;
        }
        for(j=0;j<querys[i].size();j++)
        {
            q=querys[i][j]; 
            if(q==1)
                printf("0/1\n");
            else if (q<(2+seq.size()))
                printf("%d/%d\n",seq[q-2].first,seq[q-2].second);
            else if (q==(2+seq.size())) 
                printf("1/2\n");    
            else if (q<(3+2*seq.size()))
                printf("%d/%d\n",seq[2+2*seq.size()-q].second-seq[2+2*seq.size()-q].first,seq[2+2*seq.size()-q].second);
            else if (q==(3+2*seq.size())) 
                printf("1/1\n");
                
        }
    }    
    return 0;
}