/*
91. Two squares or not two squares
Input:
10
1
2
7
14
49
9
17
76
2888
27

Output:
Yes
Yes
No
No
Yes
Yes
Yes
No
Yes
No
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
	int tN, i;
	unsigned long long int n,m,j,end;
	cin>>tN;
	vector<int> inputs;
	for(int i=0;i<tN;i++)
	{
		cin>>n;
		inputs.push_back(n);
	}
	for(i=0;i<tN;i++)
	{
		bool ret=false;
		n=inputs[i];
		end=sqrt(n/2);
		for(j=0; j<=end; j++)
		{
			m = sqrt(n-j*j);
			if((j*j+m*m)==n)
			{
				ret = true;
				break;
			}
		}
		if(ret)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
