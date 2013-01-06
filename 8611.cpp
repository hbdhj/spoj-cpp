/*
Input:
3
1 2
2 3
3 4

Output:
1 55
2 220
3 715
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int tN;
	cin>>tN;
	vector<int> inputs;
	for(int i = 0; i<tN; i++)
	{
		int input;
		cin>>input;
		cin>>input;
		inputs.push_back(input);
	}
    for(int i =0; i<tN; i++)
	{
        unsigned long long int ret=1;
        for(int j=0;j<inputs[i];j++)
            ret=ret*(10+j);
        for(int j=inputs[i];j>1;j--)
            ret=ret/j;
        cout<<i+1<<" "<<ret<<endl;
    }
	
	return 0;
}
