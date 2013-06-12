/*
TASK: Load Balancing
ALGO: simulation
 Input file:
 3
 0 99 3
 
 2
 49 50
 
 8
 16 17 15 0 20 1 1 2
 
 10
 0 0 100 0 0 0 0 0 0 0
 
 -1
 
 Output file:
 34
 -1
 23
 70
*/

#include <cstdio>
using namespace std;

int main() 
{
	int a[9000], m, n, i, val, diff;
	while(scanf("%d", &n)==1 && n>0) 
    {
		for(i = val = 0; i < n; i++) 
        {
			scanf("%d", &a[i]);
			val += a[i];
		}
		if(val % n) 
            printf("-1\n");
		else
        {
			val /= n;
			for(i = m = 0; i < n-1; i++) 
            {
				diff = a[i] - val;
				a[i+1] += diff;
				if(diff < 0) 
                    diff = -diff;
				m = m > diff? m : diff;
			}
			printf("%d\n", m);
		}
	}
	return 0;
}
