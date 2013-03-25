#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tN, n;
    cin>>tN;
    vector<int> is;
    for(int i=0; i<tN; i++)
    {    
        cin>>n;
        is.push_back(n);
    }
    vector<string> ss;
    ss.push_back("January");
    ss.push_back("February");
    ss.push_back("March");
    ss.push_back("April");
    ss.push_back("May");
    ss.push_back("June");
    ss.push_back("July");
    ss.push_back("August");
    ss.push_back("September");
    ss.push_back("October");
    ss.push_back("November");
    ss.push_back("December");
    for(int i=0; i<tN; i++)
    {
        cout<<is[i]%32<<" "<<ss[(is[i]/32)%16-1]<<" "<<is[i]/512<<endl;
    }
}