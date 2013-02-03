/*
1002. Uncle Jack
Input:
1 20
3 10
0 0
Output:
1
59049
*/
#include <stdio.h>
#include <vector>
using namespace std;
int C(int a, int b)
{
	int ret=1;
	if(b>a/2)
		b=a-b;
	for(int i=0;i<b;i++)
	{
		ret*=(a-i);
	}
	for(int i=0;i<b;i++)
	{
		ret=ret/(i+1);
	}
	//printf("C(%d,%d)=%d\n",a,b,ret);
	return ret;
}

int P(int n, int d)
{
	if(n==1)
		return 1;
	int ret=0;
	for(int i=0;i<=d;i++)
	{
		ret+=C(d,i)*P(d-i, n-1);
	}
	//printf("P(%d,%d)=%d\n",n,d,ret);
	return ret;
}

int main()
{
	int d,n;
	vector<int> ds;
	vector<int> ns;
	scanf("%d %d", &n, &d);
	printf("n=%d d=%d\n",n,d);
	while((d!=0)&&(n!=0))
	{
		ds.push_back(d);
		ns.push_back(n);
		scanf("%d %d", &n, &d);
		printf("n=%d d=%d\n",n,d);
	}
	for(int i=0;i<ds.size();i++)
	{
		printf("%d\n", P(ns[i],ds[i]));
	}
}