/*3*n*(n+1)+1*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> inputs;
	while(n>=0)
	{
		inputs.push_back(n);
		cin>>n;
	}
	for(int i=0;i<inputs.size();i++)
	{
		int root = (sqrt((float(inputs[i])-1.0)*4/3+1)-1)/2;
        //cout<<"root = "<<root<<endl;
        if((3*root*(root+1)+1)==inputs[i])
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
	}
}
