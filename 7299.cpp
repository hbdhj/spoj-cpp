/* 
7299. Multiples of 3
Sample Input :
4 7
1 0 3
0 1 2
0 1 3
1 0 0
0 0 3
1 3 3
1 0 3 

Sample Output :
4
1
0
2

Constraints :
1 <= N <= 100000
1 <= Q <= 100000
0 <= A <= B <= N - 1
*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N, Q, n;
	cin>>N;
	cin>>Q;
	vector<int> inputs;
	for(int i=0;i<3*Q;i++)
	{
		cin>>n;
		inputs.push_back(n);
	}
	vector<int> a(N, 0);
	for(int i=0;i<Q;i++)
	{
		if(inputs[3*i]==0)
		{
			for(int j=inputs[3*i+1];j<=inputs[3*i+2];j++)
				a[j]++;
		}
		else if (inputs[3*i]==1)
		{
			int ret = 0;
			for(int j=inputs[3*i+1];j<=inputs[3*i+2];j++)
				if((a[j]%3)==0)
					ret++;
			cout<<ret<<endl;
		}
	}
}