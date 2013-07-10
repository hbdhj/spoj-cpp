/*
TASK: The Great Ball
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101
int main()
{
	int t, n, a[MAX], b[MAX], total, best;
	scanf("%d", &t);
	for(int x=0;x<t;x++)
    {
		total = best = 0;

		scanf("%d", &n);
		for(int i=0;i<n;i++)
            scanf("%d%d", &a[i], &b[i]);

		sort(a, a+n);
		sort(b, b+n);

		for(int i=0,j=0; i<n && j<n; )
		{
			if(a[i] < b[j]) 
                total++, i++;
			else 
                total--, j++;

			best = max(best, total);
		}

		printf("%d\n", best);
	}
	return 0;
}
