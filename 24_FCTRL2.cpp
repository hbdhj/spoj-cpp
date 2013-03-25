#include <iostream>
#include <vector>
#include <sstream>
using namespace std; 
#define ULM 1000000000
#define MK  10000000
#define UL  unsigned long

vector<UL> t(vector<UL> ulv, UL u)
{
    vector<UL> r;
    UL inc=0;
    for(int i=0;i<ulv.size();i++)
    {
        r.push_back((ulv[i]*u+inc)%MK);
        inc = (ulv[i]*u+inc)/MK;
    }
    if(inc)
        r.push_back(inc);
    return r;
}

void f(UL u)
{
    UL ret=1;
    //cout<<"f("<<u<<") = ";
    if(u<12)
    {
        UL i=2;
        while(i<=u)
        {
            ret=ret*i;
            i++;
        }
        cout<<ret<<endl;
    }
    else
    {
        vector<UL> r;
        r.push_back(39916800);
        UL i=12;
        while(i<=u)
        {
            r=t(r,i);
            i++;
        }
        cout<<r[r.size()-1];
        for(int i=r.size()-2;i>=0;i--)
            printf("%07d",r[i]);
        cout<<endl;
    }
}

int main()
{
    int tN;cin>>tN;
    if (tN&&(tN<=100))
    {
        vector<int> ip;
        for(int i= 0; i<tN; i++) 
        {int str;cin>>str;ip.push_back(str);}
        for(int i= 0;i<tN;i++)f(ip[i]);
    }
    return 0;
}
