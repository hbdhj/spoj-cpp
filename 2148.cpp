#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tN;
    cin>>tN;
    vector<string> output;
    for(int i=0; i<tN; i++)
    {
        unsigned long long int childrenNum;
        cin>>childrenNum;
        unsigned long long int candyNumber;
        unsigned long long int candyNumTotal = 0;
        for(int j =0; j<childrenNum; j++)
        {
            cin>>candyNumber;
            candyNumTotal+=candyNumber;
            candyNumTotal=candyNumTotal%childrenNum;
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
