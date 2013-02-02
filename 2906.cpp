/*
2906. GCD2
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
Input:
2
2 6
10 11
Output:
2
1
*/
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int i,t;
	scanf("%d",&t);
	vector<int> as(t);
	vector<string> bs;
	for(i=0;i<t;i++)
	{
		char bc[500];
		scanf("%d %s",&as[i],bc);
		bs.push_back(string(bc));
	}
	for(i=0;i<t;i++)
	{
		printf("%d %s\n",as[i],bs[i].c_str());
	}
}