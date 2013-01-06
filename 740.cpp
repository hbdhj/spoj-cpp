/*
740. Treats for the Cows
Input:
5
1
3
1
5
2
Output:
43
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    unsigned long long int tN,n,k,h,t,a,r;
    cin>>tN;
    vector<int> ts;
    for(int i=0;i<tN;i++)
    {
        cin>>n;
        ts.push_back(n);        
    }
    k=0;
    a=1;
    h=0;
    t=tN-1;
    r=0;
    while(k<tN)
    {
        if(ts[h]>ts[t])
        {
            r+=ts[t]*a;
            t--;
        }
        else
        {
            r+=ts[h]*a;
            h++;
        }
        a++;
        k++;
    }
    cout<<r<<endl;
}