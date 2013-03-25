/*
8670. THE MAX LINES

Sample Input:
1
1

Sample Output:
Case 1: 4.25
*/
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int tN, r, i;
	vector<int> inputs;
	cin>>tN;
	for(i=0;i<tN;i++)
	{
		cin>>r;
		inputs.push_back(r);
	}
	for(i=0;i<tN;i++)
	{
		double r_d = double(inputs[i]);
		double out = 4*r_d*r_d +0.25;
		printf("%.2f\n", out);
	}
}
