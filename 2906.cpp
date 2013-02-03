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
0 <= A <= 40000 and A <= B < 10^250
*/
#include <stdio.h>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int gcd1(int a, int b)
{
if (b==0)
return a;
else
return gcd1(b,a%b);
}

int gcd2(int a, string b)
{
int l=b.length();
int t=ceil(float(l)/6);
int br=100000%a;
int r=0;
for(int i=0;i<t;i++)
{
int s,lr;
if((l-i*6-6)>0){s=l-i*6-6;lr=6;}else{s=0;lr=l-i*6;}
string p=string(b,s,lr);
int pi;
sscanf(p.c_str(),"%d",&pi);
if(i){r+=(pi%a)*br;br*=br;}else r+=pi%a;
}
return gcd1(r,a);
}
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
for(i=0;i<t;i++)printf("%d\n",gcd2(as[i],bs[i]));
return 0;
}