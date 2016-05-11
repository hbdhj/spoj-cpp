//
//  1837_PIE.cpp
//
//
//  Created by Haijun Deng on 13-3-19.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Pie
 */
#include <iostream>
#include <cmath>

template< class T > T sq(T &x) { return x * x; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }

const int MAX = 10001;
const double EPS = 1e-10;

double pie[MAX];

bool possible(int n, int f, double each)
{
	int i, total = 0;
	for(i = 0; i < n && total < f; i++)
    {
		total += (int)floor(pie[i] / each);
	}
	return (total >= f);
}

int main()
{
	double pi = acos(-1.0), inf = pow(10.0, 15.0);
	int n, f, t, i;
	scanf("%d", &t);
	while(t--)
    {
		scanf("%d%d", &n, &f);
		f++;
		for(i = 0; i < n; i++)
        {
			scanf("%lf", &pie[i]);
			pie[i] = sq(pie[i]) * pi;
		}
		double minv = 0.0, maxv = inf, mid, best = 0;
		for(i = 0; i < 64; i++)
        {
			mid = ( maxv + minv ) / 2.0;
			if(possible(n, f, mid))
            {
				setmax(best, mid);
				minv = mid;
			}
			else
                maxv = mid;
		}
		printf("%.4lf\n", best + EPS);
	}
	return 0;
}
