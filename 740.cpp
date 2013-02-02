/*
740. Treats for the Cows
Input:
5
1
3
1
5
2
Output:
43
*/
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int i,j,b,n,r=0;
	scanf("%d", &n);
	vector<int> inputs(n);
	for(i=0;i<n;i++)
		scanf("%d", &inputs[i]);
	i=0;
	b=0;
	j=n-1;
	while(i<j)
	{
		b++;
		if(inputs[i]<inputs[j])
		{
			r+=inputs[i]*b;
			i++;
		}
		else
		{
			r+=inputs[j]*b;
			j--;
		}
	}
	b++;
	r+=inputs[i]*b;
	printf("%d\n",r);
	return 0;
}