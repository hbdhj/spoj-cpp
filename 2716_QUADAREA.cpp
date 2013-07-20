/*
TASK: Maximal Quadrilateral Area
ALGO: geometry
 Input:
 2
 1 2 1 2
 0.5 0.5 0.5 0.5
 
 Output:
 2.00
 0.25

*/

#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int t;
	double s, m, a, b, c, d;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		s = (a+b+c+d)/2.0;
		m = sqrt((s-a)*(s-b)*(s-c)*(s-d));
		printf("%.2lf\n", m);
	}
	return 0;
}
