#include <iostream>
#include <vector>
using namespace std;
unsigned long get(unsigned long n)
{
    if(n>11)
        return get(n/2)+get(n/3)+get(n/4);
    else
        return n;
}
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
        //cout<<inputs[i]/12*13+inputs[i]%12<<endl;
        cout<<get(inputs[i])<<endl;
    }
    return 0;
}
