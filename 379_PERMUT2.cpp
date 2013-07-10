/*
 TASK: Ambiguous Permutations
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tN, ni;
    cin>>tN;
    vector<vector<int> > nll;
    while(tN>0)
    {
        vector<int> nl;
        for(int i=0;i<tN;i++)
        {
            cin>>ni;
            nl.push_back(ni);
        }
        nll.push_back(nl);
        cin>>tN;
    }
    for(int i =0; i<nll.size(); i++)
    {
        int j;
        for(j=0; j<nll[i].size(); j++)
            if(nll[i][nll[i][j]-1]!=(j+1))
                break;
        if(j<(nll[i].size()-1))
            cout<<"not ambiguous"<<endl;
        else
            cout<<"ambiguous"<<endl;
    }
    return 0;
}
