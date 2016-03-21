/*
TASK: REPROAD - Repair road
ALGO: 
Input:
2
10 1
1 1 1 1 1 1 0 0 1 1
11 2
1 0 0 1 1 0 1 0 1 1 1
Output:
*/

#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int t, i, n, j, k;
	scanf("%d", &t);
	for(i=0;i<t;i++)
    {
        scanf("%d %d",&n, &k);
		vector<int> h(n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&h[j]);
		}
		
    }
	return 0;
}