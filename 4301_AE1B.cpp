/*
Deng Haijun
4301. Tables
For the input data:
5 6 3
3 9 5 7 3
the correct result is:
3
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, k, s, ai;
    cin>>n;
    cin>>k;
    cin>>s;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        cin>>ai;
        a.push_back(ai);
    }
    sort(a.begin(),a.end());
    int b=0;
    int sum=0;
    for(int i=a.size()-1; i>=0;i--)
    {
        sum+=a[i];
        b++;
        if(sum>s*k)
            break;
    }
    cout<<b<<endl;
    return 0;
}