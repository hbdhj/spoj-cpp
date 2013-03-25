/*739*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	if(n!=0)
	{
	int ret = n;
	int remove = 0;
	int base = -2;
	vector<int> outputs;
	bool f = false;
	while(ret!=0)
	{
		outputs.push_back(abs(ret)%abs(base));
		if(f)
			ret=(ret+abs(ret)%abs(base))/abs(base);
		else
			ret=(ret-abs(ret)%abs(base))/abs(base);
		f=!f;
	}
	for(int i=outputs.size();i>0;i--)
		cout<<outputs[i-1];
	cout<<endl;
	}
	else
	{
	cout<<0<<endl;
	}
	return 0;
}
