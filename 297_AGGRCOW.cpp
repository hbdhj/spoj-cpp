/*
TASK: Aggressive cows
ALGO: binary search
Input:
1
5 3
1
2
8
4
9
Output:
3
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

//const int INF = 1000000001;
const int INF = 101;
const int MAX = 100001;

int a[MAX];

// Check whether we can find c number, which the interval is greater then dist
// e.g. possible(5, 3, 3) = true and possible(5, 3, 2) = true but possible(5, 3, 4) = false
// So return 3

bool possible(int n, int c, int dist) {
	int i, put = 1, last = a[0];
	for(i = 1; i < n && put < c; i++) 
    {
		if(a[i]-last >= dist) 
        {
			put++;
			last = a[i];
		}
	}
	return (put == c);
}
int setmax(int &a, int&b)
{
    if(a<b)
        a=b;
}
int main() {
	int t, n, i, c, maxdiff, mindiff, middiff, best;
	scanf("%d", &t);
	while(t--) 
    {
		scanf("%d%d", &n, &c);
		for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
		sort(a, a+n);
        
		maxdiff = a[n-1]-a[0];
		//maxdiff = INF;
		mindiff = best = 0;
		while(mindiff <= maxdiff) 
        {
            middiff = (maxdiff + mindiff) >> 1;
			//printf("mindiff = %d, middiff = %d, maxdiff = %d, best = %d\n", mindiff, middiff, maxdiff, best);
			if(possible(n, c, middiff)) 
            {
                //printf("possible(%d, %d, %d) = true\n", n, c, middiff);
				if(best<middiff)
                    best=middiff;
				mindiff = middiff + 1;
			}
			else 
            {
                //printf("possible(%d, %d, %d) = false\n", n, c, middiff);
				maxdiff = middiff - 1;
            }
		}
		printf("%d\n", best);
	}
	return 0;
}
