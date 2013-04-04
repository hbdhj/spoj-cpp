//
//  56_DYZIO.cpp
//  
//
//  Created by Haijun Deng on 13-4-4.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
algo: depth first search
 Input:
 9
 110011000
 [and 9 test cases more]
 
 Output:
 4
 [and 9 test cases more]
*/

#include <cstdio>
using namespace std;

const int MAX = 20002;
char str[MAX];
int len, cnt, mxd, mxc, pos;

void recur(int d) 
{
	if(str[pos]=='1') 
        cnt++;
	if(d > mxd) 
    {
		mxd = d;
		mxc = cnt;
	}
	if(str[pos++]=='1') 
    {
		recur(d+1);
		recur(d+1);
	}
}

int main() 
{
	while(scanf("%d", &len)==1) 
    {
		scanf("%s", str);
		pos = cnt = mxd = mxc = 0;
		recur(1);
		printf("%d\n", mxc);
	}
	return 0;
}