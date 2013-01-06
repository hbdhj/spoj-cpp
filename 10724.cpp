/*
10724. Sum of Tetranacci numbers (easy)
0, 0, 0, 1, 1, 2, 4, 8, 15, 29, 56, 108, 208, 401, 773, 1490, 2872, 5536, 10671, 20569, 39648, 76424, 147312, 283953, 547337
*/

#include <iostream>
#include <vector>
#define BASE 1000000007
using namespace std;
int genTetranacci(vector<unsigned long long int> &tV, unsigned long long int n)
{
    if(tV.size()>=n)
        return 0;
    else
    {
        for(unsigned long long int i=tV.size();i<=n;i++)
            //tV.push_back((2*tV[i-1]-tV[i-5])%BASE);
            tV.push_back((tV[i-1]+tV[i-2]+tV[i-3]+tV[i-4])%BASE);
    }
    return 0;
}
int main()
{
    unsigned long long int tN, m, n, i, j, ret;
    cin>>tN;
    vector<unsigned long long int> inputs;
    for(i=0; i<tN; i++)
    {
        cin>>m;
        cin>>n;
        inputs.push_back(m);
        inputs.push_back(n);
    }
    unsigned long long int myints[] = {0, 0, 0, 1, 1, 2, 4, 8, 15, 29, 56, 108, 208, 401, 773, 1490, 2872, 5536, 10671, 20569, 39648, 76424, 147312, 283953, 547337};
    vector<unsigned long long int> tV(myints, myints+sizeof(myints)/sizeof(int));
    /*genTetranacci(tV, 35);
    for(int i=0;i<=35;i++)
        cout<<tV[i]<<", ";
    cout<<endl;*/
    for(i=0; i<tN; i++)
    {
        m = inputs[2*i];
        n = inputs[2*i+1];
        cout<<m<<", "<<n<<endl;
        if(n>tV.size())
            genTetranacci(tV, n);
        ret = 0;    
        for(j=m;j<=n;j++)
        {
            ret+=tV[j];
            //cout<<ret<<endl;
            if(ret>BASE)
                ret=ret%BASE;
        }
        cout<<ret<<endl;
    }
    return 0;
}