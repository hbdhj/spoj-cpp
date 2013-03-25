/*
9199. Circular Track
*/
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

int track1(int a, int b)
{
	int k=gcd(a,b);
	return (a+b)/k;
}

int track2(int a, int b)
{
	int k=gcd(a,b);
	if(a>b)
		return (a-b)/k;
	else
		return (b-a)/k;
}

int main()
{
	int t,i;
	scanf("%d",&t);
	vector<int> inputs(t*2);
	for(i=0;i<t;i++)
	{
		scanf("%d %d", &inputs[i*2],&inputs[i*2+1]);
	}
	for(i=0;i<t;i++)
	{
		int ret;
		if((inputs[i*2]<0)&&(inputs[i*2+1]>0))
			ret=track1(0-inputs[i*2],inputs[i*2+1]);
		if((inputs[i*2]>0)&&(inputs[i*2+1]<0))
			ret=track1(inputs[i*2],0-inputs[i*2+1]);
		if((inputs[i*2]<0)&&(inputs[i*2+1]<0))
			ret=track2(0-inputs[i*2],0-inputs[i*2+1]);
		if((inputs[i*2]>0)&&(inputs[i*2+1]>0))
			ret=track2(inputs[i*2],inputs[i*2+1]);
		printf("%d\n",ret);
	}
	return 0;
}