/*
Task: Tower Of Hanoi - Revisited
ALGO: OEIS http://oeis.org/A000244
Input:
4
1
2
5
10

Output:
2
8
242
59048
*/
#include <iostream>
using namespace std;
int main()
{
	unsigned long long hanoi[35];
	hanoi[0]=2;
	for(int i=1;i<35;i++)
		hanoi[i]=hanoi[i-1]*3;
	for(int i=1;i<35;i++)
	{
		hanoi[i]+=hanoi[i-1];
		//cout<<i+1<<"th hanoi number is "<<hanoi[i]<<endl;
	}
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<hanoi[n-1]<<endl;
	}
	return 0;
}
