/* 
 TASK: Count on Cantor
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int print(int i)
{
	if(i>0)
	{
		int n = sqrt(2*i);
		while(n*(n+1)<2*i)
			n++;
		//cout<<"n = "<<n<<endl;
		int start = n*(n-1)/2+1;
		//cout<<"start = "<<start<<endl;
		if(n%2)
		{
			cout<<n+1+start-i-1<<"/"<<i-start+1<<endl;
		}
		else
		{
			cout<<i-start+1<<"/"<<(n+1+start-i-1)<<endl;
		}
		
	}
	return 0;
}

int main()
{
	int tN;
	cin>>tN;
	vector<int> inputs;
	for(int i=0; i<tN; i++)
	{
		int n;
		cin>>n;
		inputs.push_back(n);
	}
	for(int i=0; i<tN; i++)
	{
		cout<<"TERM "<<inputs[i]<<" IS ";
		print(inputs[i]);
	}
	return 0;
}
