//
//  2149_ BAISED.cpp
//  
//
//  Created by Haijun Deng on 13-4-12.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

/*
 ALGO: sorting
 Input:
 2
 
 7
 noobz 1
 llamas 2
 Winn3rz 2
 5thwheel 1
 NotoricCoders 5
 StrangeCase 7
 WhoKnows 7
 
 3
 ThreeHeadedMonkey 1
 MoscowSUx13 1
 NeedForSuccess 1
 
 Output:
 5
 3
 Explanation:
 In the first test case, one possible ranklist with the minimal badness is:
 
 1. noobz
 2. llamas
 3. Winn3rz
 4. 5thwheel
 5. NotoricCoders
 6. WhoKnows
 7. StrangeCase
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int a[100001];

int main()
{
	string name;
	int n, i, t;
	long long tot;
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(i=0; i<n; i++)
            cin >> name >> a[i];
		sort(a, a+n);
		tot = 0;
		for(i=0; i<n; i++) 
            tot += abs(a[i]-(i+1));
		cout << tot << endl;
	}
	return 0;
}