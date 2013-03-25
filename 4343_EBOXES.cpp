#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int tN, N, K, T, F;
	cin>>tN;
	vector<int> inputs;
	for(int i=0;i<tN;i++)
	{
		cin>>N;
		cin>>K;
		cin>>T;
		cin>>F;
		inputs.push_back(N);
		inputs.push_back(K);
		inputs.push_back(F);
	}
	for(int i=0;i<tN;i++)
	{
		N=inputs[3*i];
		K=inputs[3*i+1];
		F=inputs[3*i+2];
		cout<<K*(F-N)/(K-1)+N<<endl;
	}
	return 0;
}