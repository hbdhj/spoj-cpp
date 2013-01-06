/* Deng Haijun 2012/12/13
2178. He is offside!
Input:
2 3
500 700
700 500 500
2 2
200 400
200 1000
3 4
530 510 490
480 470 50 310
0 0

Output:
N
Y
N

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n1, n2, i, n;
    cin>>n1;
    cin>>n2;
    vector<vector<int> > pss;
    while((n1>0)&&(n2>0))
    {
        vector<int> ps1, ps2;
        for(int i=0;i<n1; i++)
        {
            cin>>n;
            ps1.push_back(n);
        }
        pss.push_back(ps1);
        for(int i=0;i<n2; i++)
        {
            cin>>n;
            ps2.push_back(n);
        }
        pss.push_back(ps2);
        cin>>n1;
        cin>>n2;
    }
    for(int i=0;i<pss.size()/2;i++)
    {
        sort(pss[2*i].begin(),pss[2*i].end());
        sort(pss[2*i+1].begin(),pss[2*i+1].end());
        if((pss[2*i][0]<pss[2*i+1][0])||(pss[2*i][0]<pss[2*i+1][1]))
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }
}