/*
TASK: HYDRO - Hydroelectric dams
ALGO: 
Input:
2
3
2 0 2
6
3 0 0 2 0 4
Output:
*/
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int t, i, n, j;
	scanf("%d", &t);
	for(i=0;i<t;i++)
    {
        scanf("%d",&n);
		vector<int> h(n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&h[j]);
		}
		int acme = 0;
		int water = 0;
		for(j=0;j<n;j++)
		{
			if(h[j]>acme)
				acme = h[j];
			else
				water += acme - h[j];
			//printf("h[%d] = %d, acme = %d, water = %d\n", j, h[j], acme, water);
		}
		printf("%d\n", water);
    }
	return 0;
}