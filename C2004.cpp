//
//  C2004.cpp
//  
//
//  Created by Haijun Deng on 13-1-19.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tN,i;
    cin>>tN;
    vector<string> ins(tN);
    for (i=0; i<tN; i++)
        cin>>ins[i];
    for (i=0; i<tN; i++) {
        int f,s;
        char o[2];
        sscanf (ins[i].c_str(),"%d%c%d",&f,o,&s);
        switch (o[0]) {
            case '+':
                printf("%d\n",f+s);
                break;
            case '-':
                printf("%d\n",f-s);
                break;
            case '*':
                printf("%d\n",f*s);
                break;
        }
    }
}
