//
//  3374_SCAVHUNT.cpp
//  
//
//  Created by Haijun Deng on 13-3-30.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 ALGO: ad-hoc
 Input:
 2
 4
 SwimmingPool OldTree
 BirdsNest Garage
 Garage SwimmingPool
 3
 Toilet Hospital
 VideoGame Toilet
 
 
 Output:
 Scenario #1:
 BirdsNest
 Garage
 SwimmingPool
 OldTree
 
 Scenario #2:
 VideoGame
 Toilet
 Hospital
 */
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	map< string, string > M;
	set< string > S;
	string s1, s2;
	int n, i, t, x;
	cin >> t;
	for(x=1; x<=t; x++)
	{
		M.clear();
		S.clear();
		cin >> n;
		for(i=0; i<n-1; i++)
		{
			cin >> s1 >> s2;
			M[s1] = s2;
			S.erase(s2);
			S.insert(s1);
		}
		s1 = *S.begin();
		cout << "Scenario #" << x <<":\n";
		cout << s1 << endl;
		for(i=0; i<n-1; i++)
		{
			s2 = M[s1];
			cout << s2 << endl;
			s1 = s2;
		}
		cout << endl;
	}
	return 0;
}
