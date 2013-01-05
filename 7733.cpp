/*7733*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get(int n)
{
	int ret = 0;
	while(n>0)
	{
		ret += (n%10)*(n%10);
		n=n/10;
	}
	return ret;
}

int main()
{
	int input;
	cin>>input;
	vector<int> results;
	int m = get(input);
	int repeated = false;
	while(m>1)
	{
		//cout<<m<<endl;
		if(find(results.begin(), results.end(), m)!=results.end())
		{
			repeated = true;
			break;
		}
		else
			results.push_back(m);
		m = get(m);
	}
	if(repeated)
		cout<<-1<<endl;
	else
		cout<<results.size()+1<<endl;
	return 0;
}
