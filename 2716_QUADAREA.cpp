/*
TASK: Maximal Quadrilateral Area

s=(a+b+c+d)/2
p=sqrt((s-a)*(s-b)*(s-c)*(s-d));
Input:
2
1 2 1 2
0.5 0.5 0.5 0.5
Output:
2.00
0.25
*/
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int n,i;
	scanf("%d",&n);
	vector<double> inputs(n*4);
	for(i=0;i<n*4;i++)
		scanf("%lf",&inputs[i]);
	for(i=0;i<n;i++)
	{
		double s=(inputs[i*4]+inputs[i*4+1]+inputs[i*4+2]+inputs[i*4+3])/2;
		double p=sqrt((s-inputs[i*4])*(s-inputs[i*4+1])*(s-inputs[i*4+2])*(s-inputs[i*4+3]));
		printf("%.2lf\n",p);
	}	
	return 0;	
}
