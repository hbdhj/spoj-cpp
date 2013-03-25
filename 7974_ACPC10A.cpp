#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int n1, n2, n3;
    cin>>n1;
    cin>>n2;
    cin>>n3;
    vector<string> outputs;
    while((n1!=0)||(n2!=0)||(n3!=0))
    {
        string type;
        int next;
        if(n2*2==(n1+n3))
        {
            type = "AP ";
            next = 2*n3-n2;
        }
        else if(n2*n2==n1*n3)
        {    
            type = "GP ";
            next = n3*n3/n2;
        }
        stringstream ss;
        ss<<next;
        outputs.push_back(type + ss.str());
        cin>>n1;
        cin>>n2;
        cin>>n3;
    }
    for(int i =0; i<outputs.size(); i++)
    {
        cout<<outputs[i]<<endl;
    }
    return 0;
}
