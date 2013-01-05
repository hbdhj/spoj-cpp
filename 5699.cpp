#include <iostream>
#include <vector>
using namespace std;
int gR(string stra, string strb)
{
if(stra=="0")return 0;
if(strb=="0")return 1;
int na, nb, c;
na = stra[stra.size()-1]-'0';
if(strb.size()>1)strb = strb.substr(strb.size()-2, strb.size()-1);
sscanf(strb.c_str(), "%d", &nb);
nb=(nb%4)+4;
c=1;
while(nb--)c*=na;
return c%10;
}

int main()
{
    int i, tN;
    cin>>tN;
    vector<string> is;
    for(i=0; i<tN; i++)
    {
        string in;
	cin>>in;
	is.push_back(in);
	cin>>in;
	is.push_back(in);
    }
    for(i=0;i<tN;i++)
        cout<<gR(is[i*2], is[i*2+1])<<endl;
    return 0;
}

