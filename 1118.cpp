/*
1118. Snowman
Input:
2
100
500000
Output:
10
175
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int tN,i,n;
    vector<int> inputs;
    cin>>tN;
    for(i=0;i<tN;i++)
    {
        cin>>n;
        inputs.push_back(n);
    }
    for(i=0;i<tN;i++)
    {
        float V = inputs[i];
        float R=pow((V*3/516/M_PI),1.0/3);
        int h=18*R;
        cout<<h<<endl;
    }
    return 0;
}
