//
//  2905_ NOTATRI.cpp
//  
//
//  Created by Haijun Deng on 13-3-24.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Not a Triangle
 Input:
 3
 4 2 10
 3
 1 2 3
 4
 5 2 9 6
 0
 
 Output:
 1
 0
 2
binary search 
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 2002

int A[MAX], n;

int bSearch(int start, int end, int val)
{
	int mid, i;
	while(start <= end)
	{
		if(A[start] > val) 
            return start;
		if(A[end] <= val) 
            return end+1;
		mid = (start + end) / 2;
		if(A[mid] > val) 
            end = mid - 1;
		else if(A[mid] < val) 
            start = mid + 1;
		else if(A[mid] == val)
		{
			for(i=mid+1; i<n; i++)
				if(val != A[i])
					return i;
			return i;
		}
	}
	return n;
}

int main()
{
	int i, j, cnt;
	while(scanf("%d", &n)==1 && n)
	{
		for(i=0; i<n; i++)
			scanf("%d", &A[i]);
		sort(A, A+n);
		cnt = 0;
		for(i=0; i<n-2; i++)
			for(j=i+1; j<n-1; j++)
				cnt += (n - bSearch(j+1, n-1, A[i]+A[j]));
		printf("%d\n", cnt);
	}
	return 0;
}
