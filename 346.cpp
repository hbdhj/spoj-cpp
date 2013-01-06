#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<unsigned long> inputs;
    for(int i=0;i<10;i++)
    {
        unsigned long j;
        cin>>j;
        inputs.push_back(j);
    }
    for(int i=0;i<inputs.size();i++)
    {
        cout<<inputs[i]/12*13+inputs[i]%12<<endl;
    }
    return 0;
}
