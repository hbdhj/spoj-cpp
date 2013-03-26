/*
12083. Appetizer
Input:
4
3
1 1
2 2
3 3
5
10 5
5 5
2 3
3 3
3 10
1
7 7
2
9 9
2 2
Output:
3 3
10 5
7 7
9 9
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tN, n, a, b, i, j;
    cin>>tN;
    vector<vector<int> > inputs;
    for(i=0;i<tN;i++)
    {
        vector<int> input;
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>a;
            cin>>b;
            input.push_back(a);
            input.push_back(b);
        }
        inputs.push_back(input);
    }
    for(i=0;i<tN;i++)
    {
        float max=0.0;
        int amax=0,bmax=0;
        for(j=0;j<inputs[i].size()/2;j++)
        {
            float ab = log(float(inputs[i][2*j]))*inputs[i][2*j+1];
            if(max<ab)
            {
                max=ab;
                amax=inputs[i][2*j];
                bmax=inputs[i][2*j+1];
            }
        }
        cout<<amax<<" "<<bmax<<endl;
    }    
}
