/*
 TASK: Cylinder
 Sample Input

10 10
10 50
10 30
0 0
Sample Output

54.247
785.398
412.095

 */
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int w,h;
	vector<int> ws, hs;
	cin>>w;
	cin>>h;
	while((w>0)&&(h>0))
	{
		ws.push_back(w);
		hs.push_back(h);
	}
	for(i=0; i<ws.size();i++)
	{
		if(h>(w*(M_PI+1)))
			//solution 1
		else
			//solution 2
	}
	return 0;
}
