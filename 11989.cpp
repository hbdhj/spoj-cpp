/*
11989. Factorial large
*/

#include <iostream>
#include <vector>
#define BASE 1000000007
using namespace std;
unsigned long long int genFactorial(int n)
{
    unsigned long long int ret = 1;
    for(unsigned long long int i=2;i<=n;i++)
    {
        ret=(ret%BASE)*i;
    }
    return ret%BASE;
}
int main()
{
    int tN, m, i;
    cin>>tN;
    vector<int> inputs;
    for(i=0; i<tN; i++)
    {
        cin>>m;
        inputs.push_back(m);
    }
    for(i=0; i<tN; i++)
    {
        cout<<genFactorial(inputs[i])<<endl;
    }
    return 0;
}