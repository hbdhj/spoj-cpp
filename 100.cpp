/*
100. Tower of Babylon
Sample input:
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
1
1 1 1
0

Sample output:
342
1
*/

#include <stdio.h>
#include <string.h>

#define MAX 111

struct boxtype {int x, y, z;} box[MAX];
int dp[MAX], total;

int solve(int i) {
	if(dp[i]) 
        return dp[i];
	int h, maxh, b;
	for(maxh=b=0; b<total; b++)
    {
		if(box[b].x < box[i].x && box[b].y < box[i].y)  //will not check self
        {
			if((h=solve(b))>maxh)
				maxh = h;
            //printf("   b=%d, maxh=%d\n",b,maxh);
        }
    }
    //printf("   box[%d].z=%d, dp[%d]=%d\n",i, box[i].z,i, maxh + box[i].z);    
	return dp[i] = maxh + box[i].z;
}

int main() {
	int n, i, k, x, y, z, h, maxh;
	while(scanf("%d", &n)==1 && n) 
    {
		memset(dp, 0, sizeof(dp));
		for(i=k=0; i<n; i++) 
        {
			scanf("%d%d%d", &x, &y, &z);
			box[k++] = (x<y)? (boxtype){x,y,z}:(boxtype){y,x,z};
			box[k++] = (x<z)? (boxtype){x,z,y}:(boxtype){z,x,y};
			box[k++] = (y<z)? (boxtype){y,z,x}:(boxtype){z,y,x};
		}
		total = k;
        //printf("k=%d, n=%d\n",k,n);
		for(i=maxh=0; i<total; i++)
        {
			if((h=solve(i))>maxh)
				maxh = h;
            //printf("i=%d, maxh=%d\n",i,maxh);
        }
		printf("%d\n", maxh);
	}
	return 0;
}