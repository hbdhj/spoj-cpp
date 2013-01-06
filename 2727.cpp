/* Deng Haijun 2012/12/13
2727. Army Strength
input:
2

1 1
1
1

3 2
1 3 2
5 5

output:
Godzilla
MechaGodzilla
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tN, i, n1, n2, n;
    cin>>tN;
    vector<string> outputs;
    for(i=0; i<tN; i++)
    {
        cin>>n1;
        cin>>n2;
        int max1, max2;
        max1 = 0;
        for(int j=0;j<n1; j++)
        {
            cin>>n;
            if(n>max1)max1=n;
        }
        max2=0;
        for(int j=0;j<n2; j++)
        {
            cin>>n;
            if(n>max2)max2=n;
        }
        if(max2>max1)
            outputs.push_back("MechaGodzilla");
        else
            outputs.push_back("Godzilla");
    }
    for(i=0;i<tN;i++)
    {        
        cout<<outputs[i]<<endl;        
    }
    return 0;
}
