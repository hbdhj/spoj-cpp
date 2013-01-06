/*
Deng Haijun 2012/12/18
8931. PATHS( no source code limit)
Sample Input:
3
1
2
3
Sample Output:
2
6
20
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int i, j, tN, N;
    unsigned long long int ret;
    cin>>tN;
    vector<int> inputs;
    
    for(i=0; i<tN; i++)
    {
        cin>>N;
        inputs.push_back(N);
    }
    for(i=0; i<tN; i++)
    {
        ret = 1;
        for(j=2*inputs[i]; j>inputs[i]; j--)
            ret *= j;
        for(j=1; j<=inputs[i]; j++)
            ret /= j;
        cout<<ret<<endl;
    }
    return 0;
}