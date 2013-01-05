#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int tN, n1, n2;
	cin>>tN;
	vector<int> numbers;
	for(int i=0; i<tN; i++)
	{
		cin>>n1;
		cin>>n2;
		numbers.push_back(n1);
		numbers.push_back(n2);
	}
	for(int i=0;i<tN;i++)
	{
		unsigned long long int ret=1;
		n1=numbers[2*i];
		n2=numbers[2*i+1];
		if(2*n2>n1)
			n2=n1-n2;
		for(int j=0; j<n2; j++)
			ret*=(n1-j);
		for(int j=1; j<=n2;j++)
			ret/=j;
		cout<<ret<<endl;
	}
	return 0;
}
