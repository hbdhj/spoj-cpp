/*
9821. Gaming begins here
N(n,0) = n, for all positive n. 
N(n,k) = N(1,k-1) + N(2,k-1) + ... + N(n,k-1), for all positive k, n.
Input
3 
4 0 
3 1 
3 5 
Output
4
6
28
*/
#include <iostream>
#include <vector>
using namespace std;
int Game(int n, int k)
{
    if(k==0)
        return n;
    else
    {
        int ret=0;
        for(int i=1;i<=n;i++)
            ret+=Game(i,k-1);
        return ret;    
    }
}

int main()
{
    int tN, n, k;
    cin>>tN;
    vector<int> inputs;
    for(int i=0;i<tN;i++)
    {
        cin>>n;
        inputs.push_back(n);
        cin>>k;
        inputs.push_back(k);        
    }
    for(int i=0;i<tN;i++)
    {
        cout<<Game(inputs[2*i], inputs[2*i+1])<<endl;
    }
}