/*
TASK: SMPCIRC - Two Circles
ALGO: geometry
Input:
2
103 104 5 100 100 10
103 104 10 100 100 10

Output:
E
O
*/

#include <stdio.h>

using namespace std;

int main()
{
    int tN, i;
	long x1, y1, r1, x2, y2, r2;
	long d1, d2;
    scanf("%d", &tN);
	for(i=0;i<tN;i++)
    {
        scanf("%ld %ld %ld %ld %ld %ld",&x1, &y1, &r1, &x2, &y2, &r2);
		d1 = (r2-r1)*(r2-r1);
		d2 = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
		if (d1==d2)
			printf("E\n");
		else if (d1>d2)
			printf("I\n");
		else
			printf("O\n");
    }
	return 0;
}