//
//  3979_MZVRK.cpp
//  
//
//  Created by Haijun Deng on 13-3-21.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;
long long sumd[MAX];

void calc() {
	sumd[0] = 1;
	for(int i=1; i<MAX; i++) 
        sumd[i] = (sumd[i-1]<<1) + (1LL<<i);
}

long long getSum(long long n) 
{
	int i;
	long long v, sum = 0;
	while(n) 
    {
		for(i=0; i<MAX; i++)
			if((1LL<<i) > n)
				break;
		i--; 
        v = 1LL<<i;
		sum += sumd[i] - ((i>0)?sumd[i-1]:0);
		n -= v;
	}
	return sum;
}

int main() {
	long long a, b;
	cin >> a >> b;
	calc();
	cout << getSum(b)-getSum(a-1) << endl;
	return 0;
}