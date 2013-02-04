/*
8319. GLJIVE
Increase from the first one, and stop when it closed to 100.
*/
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	int a[10], i, k, diff, res, tot;
	for(i = 0; i < 10; i++) 
		scanf("%d", &a[i]);
	for(i = 1; i < 10; i++) 
		a[i] += a[i-1];
	/*for(i = 0; i < 10; i++) 
	{
		printf("a[%d]=%d\n",i+1,a[i]);
		printf("abs(100-a[%d])=%d\n",i+1,abs(100 - a[i]));
	}*/
	diff = 100 - a[0], res = a[0];
	for(i = 1; i < 10; i++) 
	{
		k = abs(100 - a[i]);
		//for(i = 0; i < 10; i++) 
		//	printf("abs(100-a[%d])=%d\n",i+1,k);
		if(k < diff || (k==diff && a[i] > res)) 
		{
			diff = k;
			res = a[i];
		}
	}
	printf("%d\n", res);
	return 0;
}