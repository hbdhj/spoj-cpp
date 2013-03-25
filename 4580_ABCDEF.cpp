#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, m,a,b,c,d,e,f;
	cin>>n;
	vector<int> inputs;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		inputs.push_back(m);
	}
	unsigned long long int total = n*n*n*n*n*n;
	unsigned long long int ret=0;
	for(unsigned long long int i=0;i<total;i++)
	{
		a=inputs[i%n];
		b=inputs[(i/n)%n];
		c=inputs[(i/n/n)%n];
		d=inputs[(i/n/n/n)%n];
		e=inputs[(i/n/n/n/n)%n];
		f=inputs[(i/n/n/n/n/n)%n];
		
		if((a*b+c)== ((e+f)*d))
			ret++;
	}
	cout<<ret<<endl;
}