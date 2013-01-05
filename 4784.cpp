#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> output(101, 1);
	for(int i = 2; i<5; i++)
	{
		for(int j = i; j<100; )
		{
			output[j]++;
			j+=i;
		}
	}
	for(int i = 0; i<output.size(); i++)
		cout<<"output["<<i<<"] = "<<output[i]<<endl;
}
