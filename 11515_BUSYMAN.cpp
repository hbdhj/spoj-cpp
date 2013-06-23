//
//  11515_ BUSYMAN.cpp
//  
//
//  Created by Haijun Deng on 13-4-15.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

/*
 TASK: I AM VERY BUSY
 ALGO: sorting
 Sample Input: (empty lines just for clarity)
 
 3
 3
 3 9
 2 8
 6 9
 4
 1 7
 5 8
 7 8
 1 8
 6
 7 9
 0 10
 4 5
 8 9
 4 10 
 5 7

 Sample Output:
 
 1
 2
 3
 */

#include <cstdio>
#include <algorithm>
using namespace std;

pair< int, int > task[100000];

inline bool comp(const pair< int, int > &a, const pair< int, int > &b) 
{
	return (a.second == b.second) ? a.first < b.first : a.second < b.second;
}

int main() 
{
	int test, i, n, last, cnt;
	scanf("%d", &test);
	while(test--) 
    {
		scanf("%d", &n);
		for(i = 0; i < n; i++) 
            scanf("%d %d", &task[i].first, &task[i].second);
		sort(task, task + n, comp);
		cnt = 0, last = -1;
		for(i = 0; i < n; i++)
        {
			if(task[i].first >= last) 
            {
				cnt++;
				last = task[i].second;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
