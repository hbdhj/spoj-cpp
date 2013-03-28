//
//  9951_ GUANGGUN.cpp
//  
//
//  Created by Haijun Deng on 13-3-28.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 agri: Formula
 Input:
 9
 10
 
 Output:
 81
 82
 */
#include <iostream>
using namespace std;

int main()
{
	unsigned long long N, sum;
	while(cin >> N)
    {
		if(N<=9)
			cout << N*N << endl;
		else
        {
			sum = 81*(N/9) + (N%9)*(N%9);
			cout << sum << endl;
		}
	}
}
