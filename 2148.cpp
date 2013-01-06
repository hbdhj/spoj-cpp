#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //vector<unsigned long> inputs;
    int tN;
    cin>>tN;
    vector<string> output;
    for(int i=0; i<tN; i++)
    {
        //cout<<"Now get the "<<i<<"th cases"<<endl;
        unsigned long childrenNum;
        cin>>childrenNum;
        cin>>childrenNum;
        //cout<<"There are "<<childrenNum<<" children."<<endl;
        unsigned long long int candyNumber;
        unsigned long long int candyNumTotal = 0;
        for(int j =0; j<childrenNum; j++)
        {
            cin>>candyNumber;
            candyNumTotal+=candyNumber;
        }
        if(candyNumTotal%childrenNum)
            output.push_back("NO");
        else
            output.push_back("YES");        
    }
    for(int i=0;i<tN;i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}
