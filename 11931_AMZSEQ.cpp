/*
11931. AMZ Word
lst[0] = 1
lst[1] = 3
lst[i] = 2 * lst[i - 1] + lst[i - 2]
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned long long int n;
    cin>>n;
    vector<unsigned long long int> out(n+1,1);
    out[1]=3;
    for(int i=2;i<=n;i++)
    {
        out[i]=2*out[i-1]+out[i-2];
    }
    cout<<out[n]<<endl;
    return 0;
}