/*
Deng Haijun 2012/12/18
8060. Cookies Piles
SAMPLE INPUT 
3 
1 1 1 
3 5 6 
2 1 2 
 
SAMPLE OUTPUT 
1 
33 
4 
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int i, tN, N, A, D, ret;
    cin>>tN;
    vector<int> rets;
    for(i=0; i<tN; i++)
    {
        cin>>N;
        cin>>A;
        cin>>D;
        ret = (2*A+(N-1)*D)*N/2;
        rets.push_back(ret);
    }
    for(i=0; i<tN; i++)
    {
        cout<<rets[i]<<endl;
    }
    return 0;
}