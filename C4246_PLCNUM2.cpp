//
//  C4246.CPP
//
//
//  Created by Haijun Deng on 13-1-27.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    if(n==1)
        cout<<"1"<<endl;
    else if(n==2)
        cout<<"1 2"<<endl<<"4 3"<<endl;
    else
    {
        vector<vector<int> > outputs(n, vector<int>(n, 0));
        int num=1;
        for (i=0; i<n; i++) {
            outputs[0][i]=num;
            num++;
        }
        for (i=0; i<n-1; i++) {
            outputs[i+1][n-1]=num;
            num++;
        }
        bool direct=false;
        for (i=1; i<n; i++) {
            if (direct) {
                for (j=0; j<n-1; j++) {
                    outputs[n-i][j]=num;
                    num++;
                }
                direct=false;
            }
            else
            {
                for (j=n-2; j>=0; j--) {
                    outputs[n-i][j]=num;
                    num++;
                }
                direct=true;
            }
        }
        for (i=0; i<n; i++) {
            for (j=0; j<n-1; j++) {
                cout<<outputs[i][j]<<" ";
            }
            cout<<outputs[i][n-1]<<endl;
        }
    }
    return 0;
}
