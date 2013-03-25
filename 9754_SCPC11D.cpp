#include <iostream>
#include <vector>
using namespace std;
int getResult(int n1, int n2, int n3)
{
	int max = n1>n2?n1:n2;
	max = max>n3?max:n3;
	if((max*max==(n2*n2+n3*n3))||(max*max==(n1*n1+n3*n3))||(max*max==(n2*n2+n1*n1)))
		cout<<"right"<<endl;
	else
		cout<<"wrong"<<endl;
	return 0;
}
int main()
{
	int n1,n2,n3;
	cin>>n1;
	cin>>n2;
	cin>>n3;
	vector<int> inputs;
	while((n1!=0)&&(n2!=0)&&(n3!=0))
	{
		inputs.push_back(n1);
		inputs.push_back(n2);
		inputs.push_back(n3);
		cin>>n1;
		cin>>n2;
		cin>>n3;
	}
	for(int i=0; i<inputs.size()/3; i++)
	{
		getResult(inputs[i*3], inputs[i*3+1], inputs[i*3+2]);
	}
	return 0;
}