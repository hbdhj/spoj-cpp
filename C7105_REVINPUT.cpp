//
//  C7105.cpp
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
    int n;
    cin>>n;
    vector<string> is;
    char c[1025];
    while(scanf("%s",c)!=EOF)
    {
        string s=c;
        is.push_back(s);
    }
    for (int i=is.size()-1; i>=0; i--) {
        int m=n;
        while (m--) {
            for (int j=is[i].length()-1; j>=0; j--) {
                printf("%c", is[i][j]);
            }
            if(i)
                printf(" ");
        }
    }
    printf("\n");
    return 0;
}
