/*
10286. DOTA HEROES
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    vector<int> ns(t);
    vector<int> ms(t);
    vector<int> ds(t);
    vector<vector<int> > hss(t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d %d",&ns[i],&ms[i],&ds[i]);
        vector<int> hs(ns[i]);
        for(j=0;j<ns[i];j++)
        {
            scanf("%d",&hs[j]);
        }
        hss.push_back(hs);
    }
    for(i=0;i<t;i++)
    {
    }
}