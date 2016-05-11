//
//  3184_LINES.cpp
//
//
//  Created by Haijun Deng on 13-5-25.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Game of Lines
 */
#include <iostream>
#include <algorithm>

using namespace std;

struct Point { int x, y; };
struct Slope { int dx, dy; };

Point points[200];
Slope slopes[40000];

bool comp(const Slope &a, const Slope &b)
{
	return a.dx * b.dy < b.dx * a. dy;
}

bool equal(const Slope &a, const Slope &b)
{
	return a.dx * b.dy == b.dx * a. dy;
}

int main()
{
	int n, i, j, k;
	while(scanf("%d", &n) == 1 && n)
    {
		for(i = 0; i < n; i++)
            scanf("%d%d", &points[i].x, &points[i].y);
		for(i = k = 0; i < n-1; i++)
        {
			for(j = i + 1; j < n; j++, k++)
            {
				slopes[k].dx = points[i].x - points[j].x;
				slopes[k].dy = points[i].y - points[j].y;
				if(slopes[k].dy < 0)
                    slopes[k].dy *= -1, slopes[k].dx *= -1;
				if(!slopes[k].dy)
                    slopes[k].dx = abs(slopes[k].dx);
			}
		}
		sort(slopes, slopes + k, comp);
		for(i = j = 1; i < k; i++)
            j += !equal(slopes[i-1], slopes[i]);
		printf("%d\n", j);
	}
	return 0;
}
