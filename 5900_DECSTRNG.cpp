/*
5900. Decreasing Strings
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tN, n, i, j, k, l;
    vector<int> inputs;
    cin>>tN;
    for(i=0;i<tN;i++)
    {
        cin>>n;
        inputs.push_back(n);
    }
    for(i=0;i<tN;i++)
    {
        k=inputs[i]%25;
        if(k>0)
        {
            for(j=k;j>=0;j--)
                cout<<char('a'+j);
        }
        for(l=0;l<inputs[i]/25;l++)
            cout<<"zyxwvutsrqponmlkjihgfedcba";
        cout<<endl;
    }
    return 0;
}